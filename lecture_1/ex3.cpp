#include <iostream>
#include <vector>

using namespace std;

void nhap(int &a,int &b) {
	cout << "nhap 2 so:";
	cin >> a >> b;
}

void sochia(int& a, int& b) {
	int temp;
	int temp2;
	if (a > b) {
		temp = a;
	}
	else temp = b;

		for (int i = temp;i > 0;i--) {
			if ((a % i == 0) && (b % i == 0)) {
				temp2 = i;
				break;
			}
		}
		cout << temp2 << endl;
}
int main() {
	int a, b;
	nhap(a, b);
	sochia(a, b);
}
