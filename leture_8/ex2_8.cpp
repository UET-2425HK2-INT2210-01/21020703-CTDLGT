#include <iostream> // Thu vien su dung nhap xuat du lieu
using namespace std;

bool subsetSum(int a[], int n, int x, int index = 0, int currentSum = 0) {
    // Neu tong hien tai bang x => da tim duoc tap con
    if (currentSum == x) return true;

    // Neu vuot qua x hoac het phan tu thi khong hop le
    if (index == n || currentSum > x) return false;

    // Goi de quy 2 nhanh:
    // - Chon phan tu a[index]
    // - Khong chon a[index]
    return subsetSum(a, n, x, index + 1, currentSum + a[index]) || // nhanh co chon a[index]
           subsetSum(a, n, x, index + 1, currentSum);              // nhanh khong chon a[index]
}

int main() {
    int n, x;
    cin >> n >> x; // Nhap so luong phan tu va tong can tim

    int a[100]; // Mang luu cac phan tu
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Nhap tung phan tu vao mang
    }

    // Goi ham kiem tra xem co tap con nao co tong bang x khong
    if (subsetSum(a, n, x)) {
        cout << "YES"; // Neu co thi in ra YES
    } else {
        cout << "NO"; // Neu khong thi in ra NO
    }

    return 0; // Ket thuc chuong trinh
}

