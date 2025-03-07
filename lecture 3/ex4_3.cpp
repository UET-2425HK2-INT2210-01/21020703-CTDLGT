#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) {
        data = n;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {  
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < p-1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) return; 

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int p) {
        if (head == NULL) return;

        if (p == 0) {
            head = head->next;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < p - 1 && temp->next != NULL; i++)
            temp = temp->next;

        if (temp->next == NULL) return;

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0;i < n;i++) {
        string op;
        int p, x;
        cin >> op >> p;
        if (op == "insert") {
            cin >> x;
            list.insert(p, x);
        }
        else if (op == "delete") {
            list.remove(p);
        }
    }
    list.printList();
    return 0;
}

//CLASS Node:
//    DATA INTEGER data
//    POINTER Node next
//
//    FUNCTION Node(n):
//        data ? n
//        next ? NULL
//
//CLASS LinkedList:
//    POINTER Node head
//
//    FUNCTION LinkedList():
//        head ? NULL
//
//    FUNCTION insert(position, value):
//        CREATE newNode ? NEW Node(value)
//        IF position = 0 THEN
//            newNode.next ? head
//            head ? newNode
//            RETURN
//
//        temp ? head
//        FOR i FROM 0 TO position-1 DO:
//            IF temp = NULL THEN RETURN
//            temp ? temp.next
//
//        newNode.next ? temp.next
//        temp.next ? newNode
//
//    FUNCTION remove(position):
//        IF head = NULL THEN RETURN
//
//        IF position = 0 THEN
//            head ? head.next
//            RETURN
//
//        temp ? head
//        FOR i FROM 0 TO position-1 DO:
//            IF temp.next = NULL THEN RETURN
//            temp ? temp.next
//
//        nodeToDelete ? temp.next
//        temp.next ? nodeToDelete.next
//        DELETE nodeToDelete
//
//    FUNCTION printList():
//        temp ? head
//        WHILE temp ? NULL DO:
//            PRINT temp.data + " "
//            temp ? temp.next
//        PRINT newline
//insert(p, x)		O(p)	
//remove(p)			O(p)
//printList()		O(n)
