#include <iostream>
#include <vector>

using namespace std;

void nhap(vector<int>& a) {  
    cout << "Nhap 5 so: ";
    a.resize(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
}

int tong2so(vector<int>& a) { 
    int max = a[0];
    int min = a[0];

    for (int i = 1; i < 5; i++) { 
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }

    return max + min; 
}

int main() {
    vector<int> a;
    nhap(a);
    cout << "Tong so lon nhat va nho nhat: " << tong2so(a) << endl;
    return 0;
}

