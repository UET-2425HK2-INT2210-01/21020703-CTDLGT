#include<iostream>
using namespace std;

const int size = 100;
int n = 0, queue[size];

void print(){
    for(int i = 0; i < n; i++){
        cout << queue[i] << " ";
    }
    return;
}

void enqueue(int x){
    if(n == size){return;}
    queue[n] = x;
    n++;
}

void dequeue(){
    if(n == 0){return;}
    for(int i = 0; i < n - 1; i++){
        queue[i] = queue[i+1];
    }
    n--;
}

int main(){
    int n;
    cin >> n;
    int x;
    string op;
    for(int i = 1; i <=n; i++){
        cin >> op;
        if(op == "enqueue"){
            cin >> x;
            enqueue(x);
        }
        if(op == "dequeue"){
            dequeue();
        }
    }
    print();
    return 0;
}



//FUNCTION print()
//    FOR i FROM 0 TO n - 1 DO
//        PRINT queue[i] + " "
//    END FOR
//END FUNCTION
//
//FUNCTION enqueue(x)
//    IF n = MAX THEN
//        RETURN 
//    END IF
//    queue[n] ? x
//    n ? n + 1
//END FUNCTION
//
//FUNCTION dequeue()
//    IF n = 0 THEN
//        RETURN
//    END IF
//    FOR i FROM 0 TO n - 2 DO
//        queue[i] ? queue[i + 1]
//    END FOR
//    n ? n - 1
//END FUNCTION
//
//enqueue(x) 	O(1)
//dequeue()		O(n)
//print()		O(n)

