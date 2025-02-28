#include <iostream>
#include <string>

using namespace std;
void nhap(string &input) {
	printf("nhap dau vao:");
	getline(cin, input);
}

void daonguoc(string str) {
	string temp ="";
	int size = str.size();
	for (int i = 0; i < size;i++) {
		temp = str[i] + temp;
	}
	cout << temp << endl;
}

int main() {
	string a;
	nhap(a);
	daonguoc(a);
	return 0;
}
