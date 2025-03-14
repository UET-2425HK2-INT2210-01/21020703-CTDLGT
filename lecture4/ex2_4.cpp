#include <iostream>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(NULL), prev(NULL) {}
};

class PriorityQueue {
private:
    Node* head;
    Node* tail;

public:
    PriorityQueue() : head(NULL), tail(NULL) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (!head) { 
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        while (temp && temp->priority >= priority) {
            temp = temp->next;
        }

        if (!temp) { 
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else if (!temp->prev) { 
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else { 
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
    }

    void dequeue() {
        if (!head) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << "); ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string command;
        int x, p;
        cin >> command;
        
        if (command == "enqueue") {
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }
    pq.printQueue();
    return 0;
}

