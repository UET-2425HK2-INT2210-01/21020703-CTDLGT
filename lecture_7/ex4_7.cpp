#include <iostream>
using namespace std;

// Ham de quy gen ra tat ca cac chuoi nhi phan su dung thuat toan backtracking
void generateBinary(int n, string &current, int index) {
    // neu do dai da du in ra tat ca cac chuoi
    if (index == n) {
        cout << current << endl;
        return;
    }
	// y tuong cua bai toan la chon hoac khong chon bit 0 va 1 sau do quay vong
    // option chon bit 0 
    current[index] = '0';
    generateBinary(n, current, index + 1);

    // option chon bit 1
    current[index] = '1';
    generateBinary(n, current, index + 1);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    // chuoi luu cac gia tri chuoi nhi phan, khoi tao gia tri = 0
    string current(n, '0');

    // goi ham de quy sinh ra cac chuoi
    generateBinary(n, current, 0);

    return 0;
}

