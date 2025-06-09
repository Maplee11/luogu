#include <bits/stdc++.h>
using namespace std;

struct Obj {
    int price;
    int value;
};

int main() {
    int n, x;
    cin >> n >> x;

    long long totalExp = 0;
    vector<Obj> obj(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        totalExp += x;
        obj[i].value = y - x;
        obj[i].price = z;
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<long long>> dp(n, vector<long long>(x+1, 0));
    
    for (int i = obj[0].price; i <= x; i++) {
        dp[0][i] = obj[0].value;
    }

    for (int i = 1; i < n; i++) {
        int price = obj[i].price, value = obj[i].value;
        for (int avail = 0; avail < price; avail++) {
            dp[i][avail] = dp[i-1][avail];
        }
        for (int avail = price; avail <= x; avail++) {
            dp[i][avail] = max(dp[i-1][avail], dp[i-1][avail-price] + value);
        }
    }

    totalExp += dp[n-1][x];
    totalExp *= 5;
    cout << totalExp << endl;

    return 0;
}
/*

6 8
21 31 1\\
21 49 5\\
21 27 2\\
14 24 3
14 22 1
14 22 2

63 42 = 105
75 27 = 107
=212

6 8
21 52 1
21 70 5
21 48 2
14 38 3
14 36 1
14 36 0


*/