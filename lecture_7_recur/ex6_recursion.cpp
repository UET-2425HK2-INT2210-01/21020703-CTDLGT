#include<iostream>

using namespace std;
// ham tinh tong cac chu so
int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);		// lay phan du + phan du tiep theo cua so khi da /10
}

int main(){
	int n;
	cin>>n;
	cout << sumDigits(n)<< endl;
}
