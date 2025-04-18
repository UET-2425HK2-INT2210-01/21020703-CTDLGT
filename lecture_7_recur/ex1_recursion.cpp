#include <iostream>
using namespace std;
// ham tinh tong cac so lien tiep den n
int sum(int n) {	
    if (n == 1) return 1; // neu n = 1 thi return 1
    return n + sum(n - 1);		// de quy n = n + (n-1)
}

int main(){
	int n;
	cin>>n;
	cout << sum(n);
}
