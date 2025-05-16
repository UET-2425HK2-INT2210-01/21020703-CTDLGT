#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

// Gia tri vo cung dai dien cho khong co duong di giua 2 dinh
long long INF = 10000000000;

// Cau truc luu thong tin 1 canh trong do thi: dinh bat dau, dinh ket thuc, trong so
struct Canh {
    int dinhDau, dinhCuoi;
    int trongSo;
    Canh(int x, int y, int z) {
        dinhDau = x;
        dinhCuoi = y;
        trongSo = z;
    }
};

// Thuat toan Floyd-Warshall: tim duong di ngan nhat giua moi cap dinh
void floyd(vector<vector<long long>> &maTranTrongSo, int soDinh) {
    for (int k = 1; k <= soDinh; k++) {           // duyet qua dinh trung gian k
        for (int u = 1; u <= soDinh; u++) {       // duyet dinh bat dau u
            for (int v = 1; v <= soDinh; v++) {   // duyet dinh ket thuc v
                if (maTranTrongSo[u][v] > maTranTrongSo[u][k] + maTranTrongSo[k][v]) {
                    // neu duong di truc tiep tu u den v dai hon duong u -> k -> v thi cap nhat lai
                    maTranTrongSo[u][v] = maTranTrongSo[u][k] + maTranTrongSo[k][v];
                }
            }
        }
    }
}

int main() {
    int soDinh, soCanh, dinhBatDau, dinhKetThuc;

    // Doc vao so dinh, so canh, dinh bat dau va dinh ket thuc (co the dung sau)
    cin >> soDinh >> soCanh >> dinhBatDau >> dinhKetThuc;

    vector<Canh> danhSachCanh; // mang luu danh sach cac canh do thi

    // Khoi tao ma tran trong so, ban dau gan tat ca bang INF (vo cung)
    vector<vector<long long>> maTranTrongSo(soDinh + 1, vector<long long>(soDinh + 1, INF));

    int x, y, z;
    for (int i = 0; i < soCanh; ++i) { // buoc nhap cac canh cua do thi
        cin >> x >> y >> z;            // nhap dinh dau, dinh cuoi, va trong so
        Canh temp(x, y, z);            // tao doi tuong Canh
        danhSachCanh.push_back(temp);  // them canh vao danh sach
    }

    // Chuyen danh sach canh sang ma tran trong so
    for (auto canh : danhSachCanh) {
        x = canh.dinhDau;
        y = canh.dinhCuoi;
        z = canh.trongSo;
        maTranTrongSo[x][y] = z;       // gan trong so tu x den y la z
    }

    // Gan trong so bang 0 cho duong di tu dinh i den chinh no (i -> i = 0)
    for (int i = 0; i <= soDinh; ++i) {
        maTranTrongSo[i][i] = 0;
    }

    // Goi thuat toan floyd de cap nhat duong di ngan nhat
    floyd(maTranTrongSo, soDinh);

    // In ma tran trong so sau khi thuat toan floyd chay xong
    // moi dong tuong ung voi mot dinh xuat phat, moi cot tuong ung dinh ket thuc
    for (int i = 1; i <= soDinh; i++) {
        for (int j = 1; j <= soDinh; j++) {
            cout << maTranTrongSo[i][j] << " ";
        }
        cout << endl; // xuong dong sau khi in xong 1 hang
    }

    return 0;
}

