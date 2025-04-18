#include<iostream>

using namespace std;
//de quy tin day fibonacci
int fibonacci(int n) {
    if (n == 0) return 0;		// n - 0 hay 1 thi return chinh no
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); // cong thuc fibonacci
}

int main(){
	int n;
	cin>>n;
	cout<<fibonacci(n);
}
