#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) { }
};

bool Bellman_Ford(int n, int src, vector<Edge>& edges) {
    vector<int> dis(n + 1, INT_MAX);
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto& e : edges) {
            int u = e.u, v = e.v, w = e.w;
            if (dis[u] != INT_MAX) {
                dis[v] = min(dis[v], dis[u] + w);
            }
        }
    }

    for (auto& e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (dis[u] != INT_MAX && dis[v] > dis[u] + w) return false;
    }

    return true;
}

int main() {
    int T, n, m;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        vector<Edge> edges;
        edges.reserve(m);
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
            if (w >= 0) {
                edges.emplace_back(v, u, w);
            }
        }

        cout << (Bellman_Ford(n, 1, edges) ? "NO" : "YES") << endl;
    }

    return 0;
}
/*



*/