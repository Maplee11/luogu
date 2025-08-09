#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

void Dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dis, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    vector<bool> vis(n+1, 0);

    dis[src] = 0;
    minHeap.emplace(0, src);

    while (!minHeap.empty()) {
        int u = minHeap.top().second; minHeap.pop();

        if (vis[u]) continue;
        else vis[u] = 1;

        for (auto& pa : adj[u]) {
            int v = pa.first, w = pa.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                minHeap.emplace(dis[v], v);
            }
        }
    }
}

bool BellmanFord(vector<vector<pair<int, int>>>& adj, vector<int>& h, int src) {
    h[src] = 0;
    for (int i = 0; i < (n + 1) - 1; i++) {
        for (int u = 0; u <= n; u++) {
            for (auto& pa : adj[u]) {
                int v = pa.first, w = pa.second;
                h[v] = min(h[v], h[u] + w);
            }
        }
    }

    // detect neg cycle
    for (int u = 0; u <= n; u++) {
        for (auto& pa : adj[u]) {
            int v = pa.first, w = pa.second;
            if (h[u] + w < h[v]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cin >> n >> m;

    // init graph
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v) {
            if (w < 0) {
                cout << -1 << endl;
                return 0;
            }
            else continue;
        }

        adj[u].emplace_back(v, w);
    }

    // new src = 0
    adj[0].reserve(n);
    for (int i = 1; i <= n; i++) {
        adj[0].emplace_back(i, 0);
    }

    // Bellman-Ford
    vector<int> h(n+1, INT_MAX);
    if (!BellmanFord(adj, h, 0)) {
        cout << -1 << endl;
        return 0;
    }

    // reweight edges
    for (int u = 0; u <= n; u++) {
        for (auto& pa : adj[u]) {
            int v = pa.first;
            pa.second += h[u] - h[v];
        }
    }

    // Dijkstra
    vector<vector<int>> dis(n+1, vector<int>(n+1, INT_MAX));
    for (int src = 0; src <= n; src++) {
        Dijkstra(adj, dis[src], src);
    }

    // recal dis
    for (int u = 1; u <= n; u++) {
        ll ans = 0;
        for (int v = 1; v <= n; v++) {\
            if (dis[u][v] == INT_MAX) {
                dis[u][v] = 1e9;
            } else {
                dis[u][v] -= h[u] - h[v];
            }
            ans += (ll)v * (ll)dis[u][v];
        }
        cout << ans << endl;
    }

    return 0;
}
/*

重边和自环

*/