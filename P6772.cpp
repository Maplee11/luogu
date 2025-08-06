#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 50 + 5;
constexpr int MAXM = 500 + 10;
constexpr int MAXK = 200 + 10;

class Node {
public:
    int time, idx, score;
    Node(int time_, int idx_, int score_) : time(time_), idx(idx_), score(score_) {};
};

int main() {
    int n, m, T, k;
    cin >> n >> m >> T >> k;

    int scores[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }

    vector<pair<int, int>> injects[MAXN];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        injects[v].emplace_back(u, w);
    }

    unordered_map<string, int> fes;
    for (int i = 0; i < k; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        fes[to_string(t) + " " + to_string(x)] = y;
    }

    auto getBonus = [&](int t, int x) {
        auto k = to_string(t) + " " + to_string(x);
        if (fes.find(k) != fes.end()) return fes[k];
        else return 0;
    };

    // 在第 T 天, 到达 1 号城市, 基础值为 scores[1]
    queue<Node> q;
    q.emplace(T, 1, scores[1]);

    #define key(t, x) (to_string(t) + " " + to_string(x))
    unordered_map<string, int> mem;

    int ans = -1;
    while (!q.empty()) {
        auto u = q.front();
        int time = u.time, idx = u.idx, score = u.score;
        q.pop();

        // cout << "At " << time << " arrive at " << idx << " = " << score << endl;

        auto k = key(time, idx);
        if (mem.find(k) != mem.end() && mem[k] >= score) {
            continue;
        } else {
            mem[k] = score;
        }

        if (time == 0) {
            if (idx == 1) {
                ans = max(ans, score);
            }
            continue;
        }

        for (auto &pa : injects[idx]) {
            int preIdx = pa.first;
            int consume = pa.second;

            if (consume > time) continue;

            // cout << time << " -> " << time - consume << endl;
            q.push(Node(time - consume, preIdx, score + scores[preIdx] + getBonus(time - consume, preIdx)));
        }
    }

    cout << ans << endl;

    return 0;
}
/*




*/