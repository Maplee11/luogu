#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 10;
int nums[MAXN];
int dp[MAXN];

#define isSub(master, slave) ((master & slave) == slave)

int main() {
    int n;
    cin >> n;

    // input
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // pair = (tail, len)
    vector<pair<int, int>> chains;    
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int len = 1;

        for (auto it = chains.begin(); it != chains.end();) {
            if (it->first & num) {
                // tail 相同的 chain, 只保留 len 最长的; 
                len = max(len, 1 + it->second);
            }

            if (isSub(num, it->first)) {
                // 吞并 (删除) 所有被 num 完全包含的 chain
                it = chains.erase(it);
            } else {
                ++it;
            }
        }

        chains.emplace_back(num, len);
    }

    int maxLen = 0;
    for (auto &pa : chains) {
        maxLen = max(maxLen, pa.second);
    }
    cout << maxLen << endl;

    return 0;
}
/* 

9
8 1 3 7 16 9 1 7 5

8 1 3 7 5 9 1 7 5 88888

8, 1

8, 1
1, 1

8, 1
3, 2

8, 1
7, 3

8, 1
7, 3
5, 4

9, 5
7, 3
5, 4

9, 5
7, 3
5, 4
1, 6

9, 5
7, 7

9, 5
7, 7
5, 8

*/