#include <iostream>
using namespace std;

const int size = 100;

class Stack {
private:
    int arr[size];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) return; 
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) return; 
        top--;
    }

    void print() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    Stack s;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (op == "pop") {
            s.pop();
        }
    }
    
    s.print();
    
    return 0;
}

//CLASS Stack:
//    DATA ARRAY arr[MAX]
//    DATA INTEGER top
//    
//    FUNCTION Stack():
//        top ? -1
//
//    FUNCTION push(x):
//        IF top = MAX - 1 THEN RETURN
//        top ? top + 1
//        arr[top] ? x
//
//    FUNCTION pop():
//        IF top = -1 THEN RETURN
//        top ? top - 1
//
//    FUNCTION print():
//        FOR i FROM top TO 0 DO:
//            PRINT arr[i] + " "
//push(x)		O(1)	
//pop()			O(1)	
//print()		O(n)
