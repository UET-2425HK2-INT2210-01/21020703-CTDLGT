#include<iostream>

using namespace std;
//ham de quy tinh x^n
int power(int x, int n) {
    if (n == 0) return 1; // n = 0 thi return 1
    return x * power(x, n - 1); // x = x . x . x .. .. ( so lan n)
}
int main(){
	int x, n;
	cout << "nhap x va n:" ;
	cin >> x >> n;
	cout << power(x, n)<< endl;
}
