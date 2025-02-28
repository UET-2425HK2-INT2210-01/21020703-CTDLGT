#include <iostream>
#include <vector>

using namespace std;

void nhap(int& n, vector<int>& a) {  
    cout << "nhap n: ";
    cin >> n;
    a.resize(n);
    cout << "nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void sort1(int n, vector<int>& x) { 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                swap(x[j], x[j + 1]); 
            }
        }
    }

    for (int i = 0; i < n; i++) {  
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    vector<int> a;
    nhap(n, a);
    sort1(n, a);
    return 0;
}

