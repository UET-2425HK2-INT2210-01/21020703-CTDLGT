#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("matrix.txt");		// mo file input
    ofstream output("matrix.out");		// mo file output

    int m, n;
    input >> m >> n; // doc cot m va hang n cua ma tran

    int a[100][100];        // mang 2 chieu cua ma tran ban dau
    int sum[100][100] = {0}; // ma tran tich luu de luu prefix sum

    // doc tung phan tu trong file luu vao mang a
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            input >> a[i][j];

    // 2 vong for tinh tong ma tran tich luu prefix sum
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = a[i][j]
                        + sum[i - 1][j]      // tong hang phia tren
                        + sum[i][j - 1]      // tong hang ben tay trai
                        - sum[i - 1][j - 1]; // tru di tong o goc do tinh 2 lan
        }
    }

    // tao cac bien luu ket qua
    int maxSum = a[1][1]; // tao ra bien max gia su la bien o vi tri 1 1
    int r1 = 1, c1 = 1, r2 = 1, c2 = 1;	// khoi tao cac cot va hang

    // 4 vong for duyet 2 chieu cua ma tran tu (i1;j1) den (i2;j2)
    for (int i1 = 1; i1 <= m; ++i1) {
        for (int j1 = 1; j1 <= n; ++j1) {
            for (int i2 = i1; i2 <= m; ++i2) {
                for (int j2 = j1; j2 <= n; ++j2) {

                    // Tinh prefix sum tu (i1,j1) den (i2,j2)
                    int s = sum[i2][j2]
                            - sum[i1 - 1][j2]
                            - sum[i2][j1 - 1]
                            + sum[i1 - 1][j1 - 1];

                    // so sanh voi maxsum ban dau
                    if (s > maxSum) {
                        maxSum = s;  // neu lon hon thi cap nhat maxsum
                        r1 = i1;	// luu cac vi tri hang cot maxsum vao các bien
                        c1 = j1;
                        r2 = i2;
                        c2 = j2;
                    }
                }
            }
        }
    }

    cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl; // cout ra ket qua
    output << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl; // viet ra file

    input.close();
    output.close();

    return 0;
}

