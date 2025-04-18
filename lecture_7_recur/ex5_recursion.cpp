#include<iostream>

using namespace std;
//ham tinh so luong ki tu trong 1 so
int countDigits(int n) {
    if (n < 10) return 1; 	// n < 10 thi = 1
    return 1 + countDigits(n / 10);	// /10 de giam so luong chu so moi lan nhu the +1
}
int main(){
	int n;
	cin >> n;
	cout << countDigits(n) <<endl;
}

