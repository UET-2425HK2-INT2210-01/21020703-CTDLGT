#include <iostream>
using namespace std;

// Ham gen ra tat ca cac hoan vi
void generatePermutations(int arr[], bool used[], int n, int index) {
    // Neu do dai da = n thi in ra tat cac cac hoan vi
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    // Quay lui: 
    for (int i = 1; i <= n; ++i) {
        // Neu 1 phan tu chua duoc su dung
        if (!used[i]) {
            // danh dau la phan tu da duoc su d?ng
            used[i] = true;
            arr[index] = i;
            
            // de quy vi phan tiep theo bang cach chon phan tu tiep theo trong mang de de quy
            generatePermutations(arr, used, n, index + 1);
            
            // quay tro lai ban dau, danh gia la chua su dung
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    // mang luu tat ca cac hoan vi
    int arr[n];

    // mang used luu tat cac cac phan tu da su dung
    bool used[n + 1] = {false}; // +1 do chi so mang tu 1 den n
    // goi ham de quy sinh ra cac hona vi
    generatePermutations(arr, used, n, 0);

    return 0;
}

