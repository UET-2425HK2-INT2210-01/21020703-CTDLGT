#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void append(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int x) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == x) {
                cout << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* now = head;
        Node* next = NULL;
        while (now != NULL) {
            next = now->next;
            now->next = prev;
            prev = now;
            now = next;
        }
        head = prev;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
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
    for (int i = 0; i < n; i++) {
        string op;
        int x;
        cin >> op;
        if (op == "append") {
            cin >> x;
            list.append(x);
        } else if (op == "reverse") {
            list.reverse();
        } else if (op == "search") {
            cin >> x;
            list.search(x);
        }
    }
    list.printList();
    return 0;
}

