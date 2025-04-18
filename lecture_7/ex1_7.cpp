#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("numbers.txt");     // mo file input
    ofstream output("numbers.sorted"); // mo file output

    int arr[1000];						// mang luu so
    int n = 0;							// bien dem
    int x;								// bien temp luu phan tu duoc doc

    while (input >> x) {
        arr[n++] = x;					// doc tung phan tu trong file
    }

   // bubble sort bang 2 vong for
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {		// so sanh 2 so lien nhau neu so sau nho hon so truoc thi swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {   		// cout mang da sap xep
        cout<< arr[i] <<" ";
    }
    
    for (int i = 0; i < n; ++i) {
        output << arr[i];					// luu mang da sort vao output
        if (i < n - 1) output << " ";
    }

    input.close();							// dong file output va input
    output.close();

    return 0;
}

