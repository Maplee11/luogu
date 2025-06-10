#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000;
constexpr int MAXM = 200;
constexpr int mod = 1000000007;
int dpArr[MAXN][MAXM][2] = {};

#define dp(i, j, k) (dpArr[i][j][(k)%2])

int countOccurrences(const string &sa, const string &sb) {
    int count = 0;
    size_t pos = 0;
    while ((pos = sa.find(sb, pos)) != string::npos) {
        ++count;
        ++pos;
    }
    return count;
}

int main() {
    int n, m, parts;
    cin >> n >> m >> parts;

    string a, b;
    cin >> a; cin >> b;

    // k = 1
    for (int j = 0; j < m; j++) {
        dp(j, j, 1) = countOccurrences(a.substr(0, j + 1), b.substr(0, j + 1));
        for (int i = j + 1; i < n; i++) {
            dp(i, j, 1) = dp(i-1, j, 1) + (a[i] == b[j] && a.substr(i - (j + 1) + 1, j + 1) == b.substr(0, j + 1));
        }
    }

    // dp
    for (int k = 2; k <= parts; k++) {
        for (int j = 1; j < m; j++) {
            for (int i = j; i < n; i++) {
                dp(i, j, k) = dp(i-1, j, k) % mod;
                if (a[i] == b[j]) {
                    for (int offset = 0; a[i-offset] == b[j-offset] && j-offset >= k-1; offset++) {
                        dp(i, j, k) = (dp(i, j, k) + dp(i-1-offset, j-1-offset, k-1)) % mod;
                    }
                }
            }
        }
    }

    cout << dp(n-1, m-1, parts) << endl;

    return 0;
}
/*

10 4 2
cadbabtbai
abab


6 3 2
aabaab
aab




*/