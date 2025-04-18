#include<iostream>

using namespace std;

//de quy tinh n!
int factor(int n) {
    if (n == 0 || n == 1) return 1;	// neu n = 1 hoac 0 thi reutnr 1
    return n * factorial(n - 1);	// de quy n = n . (n-1)
}

int main(){
	int n;
	cin>>n;
	cout << factor(n);
}
