#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 100003;
constexpr int MAXN = 1e6 + 10;

int path[MAXN] = {};
int vis[MAXN] = {};
unordered_multiset<int> adj[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != y) {
            adj[x].insert(y);
            adj[y].insert(x);
        }
    }

    queue<int> q;

    vis[1] = 1;
    path[1] = 1;
    q.push(1);

    int stamp = 1;
    while (!q.empty()) {
        int siz = q.size();
        stamp++;

        while (siz--) {
            int u = q.front();
            q.pop();
    
            for (auto v : adj[u]) {
                if (vis[v] == 0) {
                    path[v] = (path[v] + path[u]) % mod;
                    vis[v] = stamp;
                    q.push(v);
                    adj[v].erase(u);
                } else if (vis[v] == stamp) {
                    path[v] = (path[v] + path[u]) % mod;
                    adj[v].erase(u);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", path[i]);
    }

    return 0;
}
/*



*/