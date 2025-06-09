#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 262144 + 10;
constexpr int MAXM = 40 + 2;

// tail -> pos
int chains[MAXN][MAXM];

int nums[MAXN];
int ans;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAXM; j++) {
            chains[i][j] = -1;
        }
    }

    chains[0][nums[0]] = 0;
    ans = nums[0];
    for (int i = 1; i < n; i++) {
        int num = nums[i];
        chains[i][num] = i;
        ans = max(ans, num);

        auto mpPos = i - 1;
        int curNum = num, curPos = i;
        while (1) {
            auto &ch = chains[mpPos];
            if (ch[curNum] != -1) {
                curPos = ch[curNum];
                curNum++;

                chains[i][curNum] = curPos;
                ans = max(ans, curNum);
                
                if (curPos > 0) {
                    mpPos = curPos - 1;
                    continue;
                }
            }
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
/* 

0 1 2 3 4 5 6 7 8
9
5 4 2 1 1 3 4 5 6

5(0)
4(1)
2(2)
1(3)
1(4) 2(3) 3(2)
3(5) 4(2) 5(1) 6(0)
4(6) 5(2)
5(7) 6(2)
6(8) 7(2)


*/