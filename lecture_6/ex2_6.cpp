#include <iostream>
using namespace std;

class MinHeap {
public:
    int* arr; // Mang luu tru cac phan tu cua heap
    int n; // So luong phan tu hien tai trong heap

    MinHeap() {
        n = 0;
        arr = new int[1000]; // Khoi tao mang co kich thuoc toi da
    }

    // Ham day phan tu len de dam bao tinh chat cua heap
    void heapifyUp(int idx) {
        int parent;
        while (idx > 0) {
            parent = (idx - 1) / 2; // Tinh chi so cua node cha
            if (arr[idx] < arr[parent]) { // So sanh voi node cha
                swap(arr[idx], arr[parent]); // Doi cho neu vi pham tinh chat heap
                idx = parent; // Cap nhat chi so de tiep tuc day len
            } else {
                break; // Dung lai neu khong can thay doi
            }
        }
    }

    // Ham them mot phan tu vao heap
    void insert(int val) {
        arr[n] = val; // Them phan tu moi vao cuoi heap
        heapifyUp(n); // Dieu chinh lai heap neu can
        n++; // Tang kich thuoc heap
    }

    // Ham day phan tu xuong de dam bao tinh chat cua heap
    void heapifyDown(int idx) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        // Kiem tra va tim phan tu nho nhat trong ba phan tu
        if (left < n && arr[left] < arr[smallest]) smallest = left;
        if (right < n && arr[right] < arr[smallest]) smallest = right;

        if (smallest != idx) {
            swap(arr[idx], arr[smallest]);
            heapifyDown(smallest); // De quy goi lai de sap xep dung
        }
    }

    // Ham xoa mot phan tu khoi heap
    void remove(int val) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == val) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return; // Neu khong tim thay gia tri can xoa

        arr[idx] = arr[n - 1]; // Thay the phan tu can xoa bang phan tu cuoi cung
        n--; // Giam kich thuoc cua heap
        heapifyDown(idx); // Dieu chinh lai heap
    }
};

int main() {
    MinHeap heap;

    // Them cac phan tu vao heap
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35};
    for (int value : values) heap.insert(value);

    // Xoa cac phan tu khoi heap
    int toDelete[] = {6, 13, 35};
    for (int value : toDelete) heap.remove(value);

    // In cac phan tu trong heap
    cout << "Cac phan tu trong heap: ";
    for (int i = 0; i < heap.n; i++) {
        cout << heap.arr[i] << " ";
    }
    return 0;
}

