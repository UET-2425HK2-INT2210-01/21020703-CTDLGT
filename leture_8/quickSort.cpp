#include <iostream>
using namespace std;

// function swap doi cho a va b
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// cach chia va chon theo lomuto
int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chon phan tu cuoi cung lam pivot
    int i = low - 1;       // vi tri cua cac phan tu nho hon pivo

    for (int j = low; j < high; j++) {	//duyet vong for cho mang co tri so nho hon
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // dua phan tu nho hon ve ben tay trai
        }
    }
    swap(arr[i + 1], arr[high]); // dua pivot ve dung vi tri 
    return i + 1;                // tra ve chi so cua pivot
}

// Quick Sort 
void quickSortLomuto(int arr[], int n) {
    int stack[1000];    // khoi tao mang stack
    int top = -1;

    stack[++top] = 0;      // dua chi so bat dau vao stack
    stack[++top] = n - 1;  // dua chi so ket thuc vao stack

    while (top >= 0) {
        int high = stack[top--]; // lay phan ket thuc
        int low = stack[top--];  // Lay phan bat dau

        int p = lomutoPartition(arr, low, high); // chia mang theo cach chia cua lomuto

        // Neu con phan tu ben trai pivot thi dua vao stack
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // Neu con phan tu ben phai pivot thi dua vao stack
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// Cach chia mang theo Hoare
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low]; // Chon pivot la phan tu dau tien
    int i = low - 1;      // Chi so ben trai
    int j = high + 1;     // Chi so ben phai

    while (true) {
        do {
            i++;          // Tim phan tu >= pivot ben trai
        } while (arr[i] < pivot);

        do {
            j--;          // Tim phan tu <= pivot ben phai
        } while (arr[j] > pivot);

        if (i >= j)  // Neu chi so ben trai >= chi so ben phai, tra ve j
            return j;

        swap(arr[i], arr[j]); // Hoan doi hai phan tu sai vi tri
    }
}

// Ham quick sort su dung cach chia Hoare
void quickSortHoare(int arr[], int n) {
    int stack[1000]; // Khoi tao stack de mo phong de quy
    int top = -1;    // Khoi tao top cua stack

    stack[++top] = 0;      // Dua chi so bat dau vao stack
    stack[++top] = n - 1;  // Dua chi so ket thuc vao stack

    while (top >= 0) {
        int high = stack[top--];  // Lay chi so ket thuc
        int low = stack[top--];   // Lay chi so bat dau

        int p = hoarePartition(arr, low, high); // Chia mang theo cach chia Hoare

        // Neu con phan tu ben trai pivot thi dua vao stack
        if (p > low) {
            stack[++top] = low;
            stack[++top] = p;
        }

        // Neu con phan tu ben phai pivot thi dua vao stack
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}


int main() {
    int arr1[] = {5, 3, 7, 2, 8, 1, 4};		// mang test lomuto
    int arr2[] = {5, 3, 7, 2, 8, 1, 4};		// mang test Hoare
    int n = sizeof(arr1) / sizeof(arr1[0]);

    quickSortLomuto(arr1, n);
    quickSortHoare(arr2, n);

    cout << "Quick sort Lomuto: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\n";

    cout << "Quick sort Hoare:  ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\n";

    return 0;
}
