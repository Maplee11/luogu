#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 35;

int main() {
    int n;
    cin >> n;

    int scores[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }

    pair<int, int> dp[MAXN][MAXN];
    #define dp(i, j) dp[i][j]

    // init dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp(i, j) = pair<int, int>(0, 0);
        }
    }

    int tree[MAXN][2] = {};

    function<pair<int, int>(int, int)> dfs = [&](int l, int r) {
        if (l > r) return pair<int, int>(1, 0);

        // is in mem
        if (dp(l, r).first != 0) return dp(l, r);

        int len = r - l + 1;

        
        // boundary
        if (len == 1) {
            return dp(l, r) = pair<int, int>(scores[l], l);
        }
        if (len == 2) {
            return dp(l, r) = pair<int, int>(scores[l] + scores[r], l);
        }
        
        pair<int, int> ret(INT_MIN, 0);
        for (int k = l; k <= r; k++) {
            auto lsub = dfs(l, k - 1);
            auto rsub = dfs(k + 1, r);
            if (lsub.first * rsub.first + scores[k] > ret.first) {
                ret.first = lsub.first * rsub.first + scores[k];
                ret.second = k;
            }
        }

        // cout<<l<<" "<<r<<" = "<<ret<<endl;
        
        return dp(l, r) = ret;
    };

    cout << dfs(1, n).first << endl;

    function<void(int, int)> pre = [&](int l, int r) {
        if (l > r) return;

        int root = dp(l, r).second;
        cout << root << " ";

        pre(l, root - 1);
        pre(root + 1, r);
    };

    pre(1, n);
    cout << endl;

    return 0;
}
/*



*/