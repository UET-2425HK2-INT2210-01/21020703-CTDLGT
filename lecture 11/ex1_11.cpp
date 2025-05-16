#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

long long INF = 100000000001;

// Cau truc luu canh giua 2 dinh va trong so
struct Canh {
    int dau, cuoi;
    int trongSo;
    Canh(int x, int y, int z) {
        dau = x;
        cuoi = y;
        trongSo = z;
    }
};

// Thuat toan Bellman-Ford tim duong di ngan nhat tu dinh bat dau
void BellmanFord(int soDinh, int dinhBatDau, vector<Canh> danhSachCanh, vector<long long>& khoangCach, vector<int>& truyVet) {
    khoangCach[dinhBatDau] = 0; // Khoang cach tu dinh bat dau den chinh no la 0

    for (int i = 1; i < soDinh; ++i) { // Duyet soDinh - 1 lan
        for (auto canh : danhSachCanh) {
            int u = canh.dau;
            int v = canh.cuoi;
            int w = canh.trongSo;

            // Neu co the di tu u -> v va duong di moi ngan hon thi cap nhat
            if (khoangCach[u] != INF && khoangCach[v] > khoangCach[u] + w) {
                khoangCach[v] = khoangCach[u] + w;
                truyVet[v] = u; // Luu lai duong di ngan nhat dan den v
            }
        }
    }
}

// Ham truy vet va in duong di tu dinhBatDau den dinhKetThuc
void InDuongDi(int dinhBatDau, int dinhKetThuc, vector<int> truyVet, vector<long long> khoangCach) {
    if (truyVet[dinhKetThuc] == -1) {
        cout << "Khong co duong di ngan nhat tu " << dinhBatDau << " den " << dinhKetThuc << endl;
        return;
    }

    cout << "Tong trong so: " << khoangCach[dinhKetThuc] << endl;

    vector<int> duongDi;
    int dinhHienTai = dinhKetThuc;

    while (dinhHienTai != dinhBatDau) {
        duongDi.push_back(dinhHienTai);
        dinhHienTai = truyVet[dinhHienTai];
    }

    duongDi.push_back(dinhBatDau);
    reverse(duongDi.begin(), duongDi.end());

    cout << "Duong di ngan nhat: ";
    for (int dinh : duongDi) {
        cout << dinh << " ";
    }
    cout << endl;
}

int main() {
    int soDinh, soCanh, dinhBatDau, dinhKetThuc;
    cin >> soDinh >> soCanh >> dinhBatDau >> dinhKetThuc;

    vector<Canh> danhSachCanh;
    vector<long long> khoangCach(soDinh + 1, INF);
    vector<int> truyVet(soDinh + 1, -1);

    // Nhap danh sach cac canh
    for (int i = 0; i < soCanh; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        danhSachCanh.emplace_back(u, v, w);
    }

    // Chay thuat toan Bellman-Ford
    BellmanFord(soDinh, dinhBatDau, danhSachCanh, khoangCach, truyVet);

    // In ket qua
    InDuongDi(dinhBatDau, dinhKetThuc, truyVet, khoangCach);

    return 0;
}

