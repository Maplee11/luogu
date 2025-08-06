#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "ACDADCC";
    cin >> s;
    
    int n = s.length();

    unordered_map<string, int> mem;
    function<int(int, int)> dfs = [&](int l, int r) {
        int len = r - l + 1;
        string ss = s.substr(l, len);

        // in mem
        if (mem.find(ss) != mem.end()) return mem[ss];

        // boundary
        if (len == 1) return mem[ss] = 1;

        if (s[l] == s[r]) return mem[ss] = min(dfs(l + 1, r), dfs(l, r - 1));

        // dfs
        int ans = INT_MAX;
        for (int idx = l; idx < r; idx++) {
            ans = min(ans, dfs(l, idx) + dfs(idx + 1, r));
        }

        return mem[ss] = ans;
    };

    cout << dfs(0, n - 1) << endl;

    return 0;
}
/*

RGBGRB 4

ACDABCC 5

ACDADCC 4

*/