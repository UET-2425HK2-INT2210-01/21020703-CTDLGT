#include <iostream>    
using namespace std;

const int MAX = 100000;  
int temp[MAX];            // Mang tam thoi de luu tru khi merge

// ham merge 2 tap con cua mang arr tu [L den m] va tu [m+1 den r]
void merge(int arr[], int l, int m, int r) {
    int i = l;            // danh dau bat dau mang doan dau
    int j = m + 1;        // danh dau bat dau mang doan sau
    int k = l;            // danh dau mang temp

    // tron tung phan tu cua 2 tap con vao mang temp
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])    // neu trai nho hon phai
            temp[k++] = arr[i++]; // gan vao temp roi tang i, k len de duyet
        else
            temp[k++] = arr[j++]; // gan vao phan tu ben phai vao temp roi tang j, k
    }

    // copy phan acon lai cua doan trai
    while (i <= m)
        temp[k++] = arr[i++];

    // Copy phan con lai cua doan ben phai
    while (j <= r)
        temp[k++] = arr[j++];

    // Copy nguojc lai tu mang temp vao mang chinh
    for (int i = l; i <= r; ++i)
        arr[i] = temp[i];
}

// Ham merge sort 
void mergeSort(int arr[], int n) {
    // khoi dau voi doan co co kich thuoc la 1 sau do ^2 len
    for (int width = 1; width < n; width *= 2) {
        // Duyet toang bo mang con theo tung cap co kich thuoc la width
        for (int i = 0; i < n; i += 2 * width) {
            int l = i;                          // doan bat dau ( ben trai )
            int m = min(i + width - 1, n - 1);  // chi so doan giua ( cuoi cua doan trai )
            int r = min(i + 2 * width - 1, n - 1); // chi so cuoi cua doan phai

            if (m < r)                          // neu co 2 doan con thi bat dau merge
                merge(arr, l, m, r);
        }
    }
}

int main() {
    int n;                   
    cin >> n;            
    int arr[MAX];          
    for (int i = 0; i < n; ++i)  //cin vao tung phan tu cua mang
        cin >> arr[i];
    mergeSort(arr, n); 			// mergesort 
    for (int i = 0; i < n; ++i)  
        cout << arr[i] << " ";
    return 0;              
}

