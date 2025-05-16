#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000; // Gioi han so dinh

vector<int> adj[MAXN];  // Danh sach ke (luu cac dinh ke voi moi dinh)
bool visited[MAXN];     // Mang danh dau dinh da duyet hay chua

// Ham DFS de duyet cac dinh trong thanh phan lien thong
void dfs(int u) {
    visited[u] = true; // Danh dau dinh u da duoc tham

    // Duyet tat ca cac dinh ke voi u
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v); // Goi de quy voi dinh chua duyet
        }
    }
}

int main() {
    int n, m; // n: so dinh, m: so canh
    cin >> n >> m;

    // Doc cac canh va xay dung danh sach ke
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Them y vao danh sach ke cua x
        adj[y].push_back(x); // Them x vao danh sach ke cua y (vi do thi vo huong)
    }

    int connectedComponents = 0; // Bien dem so thanh phan lien thong

    // Duyet tat ca cac dinh tu 1 den n
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ++connectedComponents; // Tang dem neu tim thay thanh phan moi
            dfs(i); // Tham cac dinh trong thanh phan nay
        }
    }

    // In ra so thanh phan lien thong
    cout << connectedComponents << endl;

    return 0;
}

