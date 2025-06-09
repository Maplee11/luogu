#include <bits/stdc++.h>
using namespace std;

struct Herb {
    int time;
    int value;
} herb[110];

int main() {
    int totalTime, n;
    cin >> totalTime >> n;

    for (int i = 0; i < n; i++) {
        cin >> herb[i].time >> herb[i].value;
    }

    // dp[n][totalTime]
    vector<vector<int>> dp(n, vector<int>(totalTime + 1, 0));

    for (int time = herb[0].time; time <= totalTime; time++) {
        dp[0][time] = herb[0].value;
    }

    for (int i = 1; i < n; i++) {
        int t = herb[i].time, val = herb[i].value;
        for (int time = 1; time <= t-1; time++) {
            dp[i][time] = dp[i-1][time];
        }
        for (int time = t; time <= totalTime; time++) {
            dp[i][time] = max(dp[i-1][time], dp[i-1][time-t] + val);
        }
    }

    cout << dp[n-1][totalTime] << endl;

    return 0;
}