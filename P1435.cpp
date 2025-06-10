#include <bits/stdc++.h>
using namespace std;

bool contains(unordered_map<string, int> &dic, const string &key) {
    return dic.find(key) != dic.end();
}

int main() {
    string s;
    cin >> s;
    
    int n = s.length();

    unordered_map<string, int> mem;
    function<int(int, int)> dfs = [&](int l, int r) {
        int len = r - l + 1;
        string str = s.substr(l, len);

        // is in memory
        if (contains(mem, str)) return mem[str];

        // boundary
        if (len <= 1) return mem[str] = 0;
        if (len == 2) return mem[str] = (str[0] != str[1]);
        if (s[l] == s[r]) return mem[str] = dfs(l + 1, r - 1);

        // dfs
        return mem[str] = min(dfs(l, r - 1), dfs(l + 1, r)) + 1;
    };

    cout << dfs(0, n - 1) << endl;

    return 0;
}
/*



*/