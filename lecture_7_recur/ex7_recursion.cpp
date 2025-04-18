#include<iostream>
using namespace std;

//ham dao nguoc so nguyen
int reverseNumber(int n, int rev = 0) {
    if (n == 0) return rev;// trong truong hop : n = 0 thì return revNum; 
    return reverseNumber(n / 10, rev * 10 + n % 10); //goi dequy
}

 int main(){
 	int n;
 	cin >> n;
 	cout << reverseNumber(n) <<endl;
 }
