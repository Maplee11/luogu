#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, src;
    cin >> n >> m >> src;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    vector<bool> vis(n + 1);
    vector<int> dis(n + 1, INT_MAX);

    dis[src] = 0;
    minHeap.emplace(0, src);

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

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

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }

    return 0;
}
/*



*/