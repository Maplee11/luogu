#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Obj {
    ll price, value;
    Obj *s = nullptr, *ss = nullptr;
    int idx;
};

int main() {
    int n, totMoney;
    cin >> totMoney >> n;

    vector<Obj> obj(n);
    for (int i = 0; i < n; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        obj[i].price = v;
        obj[i].value = v*p;
        obj[i].idx = i;
        if (q > 0) {
            obj[i].idx = -1;
            if (obj[q-1].s) obj[q-1].ss = new Obj(obj[i]);
            else obj[q-1].s = new Obj(obj[i]);
        }
    }

    auto it = obj.begin();
    while (it != obj.end()) {
        if (it->idx == -1) {
            it = obj.erase(it);
        } else it++;
    }

    n = obj.size();

    vector<vector<ll>> dp(n, vector<ll>(totMoney+1, 0));
    for (int i = obj[0].price; i <= totMoney; i++) {
        dp[0][i] = obj[0].value;
    }

    for (int i = 1; i < n; i++) {
        int price = obj[i].price, value = obj[i].value;
        Obj *s = obj[i].s, *ss = obj[i].ss;
        
        for (int money = 0; money <= totMoney; money++) {
            if (money >= price) {
                dp[i][money] = max(dp[i-1][money], dp[i-1][money-price] + value);
            }
            if (s && money >= price + s->price) {
                dp[i][money] = max(dp[i][money], dp[i-1][money-price-s->price] + value + s->value);
            }
            if (ss && money >= price + ss->price) {
                dp[i][money] = max(dp[i][money], dp[i-1][money-price-ss->price] + value + ss->value);
            }
            if (obj[i].s && obj[i].ss && money >= price + s->price + ss->price) {
                dp[i][money] = max(dp[i][money], dp[i-1][money-price-s->price-ss->price] + value + s->value + ss->value);
            }
        }
    }

    cout << dp[n-1][totMoney] << endl;

    return 0;
}
/*

1000 5
400 3 0
200 5 4
300 2 0
900 2 0
100 5 4

*/