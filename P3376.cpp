#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll res[210][210] = {};

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        res[u][v] += w;
    }
    
    vector<int> pre(n + 1, 0);
    auto bfs = [&]() {
        fill(pre.begin(), pre.end(), 0);
        queue<int> q;

        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v = 1; v <= n; v++) {
                assert(res[u][v] >= 0);
                if (pre[v] || res[u][v] == 0) continue;

                pre[v] = u;
                q.push(v);

                if (v == t) {
                    return true;
                }
            }
        }

        return false;
    };

    ll maxFlow = 0;
    while (bfs()) {
        // calculate flow
        ll flow = LLONG_MAX;
        for (int v = t; v != s; v = pre[v]) {
            int u = pre[v];
            flow = min(flow, res[u][v]);
        }
        
        // push flow
        for (int v = t; v != s; v = pre[v]) {
            int u = pre[v];
            res[u][v] -= flow;
            res[v][u] += flow;
        }

        maxFlow += flow;
    }

    cout << maxFlow << endl;

    return 0;
}
/*

4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 30


*/