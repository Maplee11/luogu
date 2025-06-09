#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(arr[i], arr[i] + dp[i-1]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}
/*

7
2 -4 3 -1 2 -4 3

*/