#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_X = 10000;

int weight[MAX_N]; // Mang luu trong luong cua cac mon do
int value[MAX_N];  // Mang luu gia tri cua cac mon do
int dp[MAX_N + 1][MAX_X + 1]; // Bang quy hoach dong

int knapsack(int n, int X) {
    // Duyet tung mon do
    for (int i = 1; i <= n; ++i) {
        // Duyet trong luong tu 0 den X
        for (int w = 0; w <= X; ++w) {
            if (weight[i - 1] <= w) {
                // Chon max giua khong chon mon do nay va chon no
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            } else {
                // Khong the chon mon do nay vi qua nang
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][X]; // Tra ve gia tri lon nhat co the dat duoc
}

int main() {
    int n, X;
    cin >> n >> X; // Nhap so luong mon do va trong luong toi da

    // Nhap trong luong va gia tri cua tung mon do
    for (int i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];

    // Goi ham giai bai toan
    cout << knapsack(n, X) << endl;
    return 0;
}

