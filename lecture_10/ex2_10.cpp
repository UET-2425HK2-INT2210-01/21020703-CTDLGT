#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ham BFS de tim duong di ngan nhat
void bfs(int n, vector<vector<int>>& adj, int start, vector<int>& dist) {
    // Khoi tao tat ca khoang cach la -1 (vo cuc, chua tham)
    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;
    }

    dist[start] = 0; // Khoang cach tu start den chinh no la 0

    queue<int> q; // Hang doi BFS
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Duyet qua cac dinh ke cua u
        for (int v : adj[u]) {
            if (dist[v] == -1) { // Neu chua tham
                dist[v] = dist[u] + 1; // Cap nhat khoang cach
                q.push(v);
            }
        }
    }
}

// Ham shortestPath su dung BFS de tim duong di ngan nhat tu start den end
int shortestPath(int n, vector<vector<int>>& adj, int start, int end) {
    vector<int> dist(n + 1); // Mang luu khoang cach tu start den cac dinh
    bfs(n, adj, start, dist); // Goi BFS de cap nhat khoang cach

    return dist[end]; // Tra ve khoang cach den dinh end
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y; // n dinh, m canh, tim tu x den y

    vector<vector<int>> adj(n + 1); // Danh sach ke, 1-based index

    // Doc m canh cua do thi
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Do thi co huong
    }

    // In ra duong di ngan nhat tu x den y
    cout << shortestPath(n, adj, x, y) << endl;

    return 0;
}

