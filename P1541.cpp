#include <bits/stdc++.h>
using namespace std;

static constexpr int MAXN = 42;
int dp[MAXN][MAXN][MAXN][MAXN] = {};

int main() {
    int n, m;
    cin >> n >> m;

    // input
    int scores[400];
    int cards[5];
    
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cards[tmp]++;
    }

    int na = cards[1], nb = cards[2], nc = cards[3], nd = cards[4];

    dp[0][0][0][0] = scores[1];

    for (int a = 0; a <= na; a++) {
        for (int b = 0; b <= nb; b++) {
            for (int c = 0; c <= nc; c++) {
                for (int d = 0; d <= nd; d++) {
                    if ((a | b | c | d) == 0) continue;
                    if (a > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a-1][b][c][d]);
                    if (b > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b-1][c][d]);
                    if (c > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c-1][d]);
                    if (d > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d-1]);
                    dp[a][b][c][d] += scores[1 + a + b * 2 + c * 3 + d * 4];
                }
            }
        }
    }

    cout << dp[na][nb][nc][nd] << endl;

    return 0;
}
/* 

9 5
6 10 14 2 8 8 18 5 17
1 3 1 2 1


*/