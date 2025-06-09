#include <bits/stdc++.h>
using namespace std;

int minMax(vector<int> &nums, int left, int right, int idx) {
    // boundary
    if (idx == nums.size()) {
        return max(left, right);
    }

    int num = nums[idx];
    int mm1 = minMax(nums, left + num, right, idx + 1);
    int mm2 = minMax(nums, left, right + num, idx + 1);
    return min(mm1, mm2);
}

int main() {
    int lens[4];

    #ifdef LOCAL_RUN
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d %d %d %d", &lens[0], &lens[1], &lens[2], &lens[3]);
    #else
    cin >> lens[0] >> lens[1] >> lens[2] >> lens[3];
    #endif
    

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int n = lens[i];
        vector<int> nums(n);

        for (int j = 0; j < n; j++) {
            #ifdef LOCAL_RUN
            fscanf(f, "%d", &nums[j]);
            #else
            cin >> nums[j];
            #endif
        }
        
        sort(nums.begin(), nums.end());
        int overhead = minMax(nums, 0, 0, 0);

        // cout<<"overhead = "<<overhead<<endl;
        ans += overhead;
    }

    cout<<ans<<endl;

    return 0;
}
/*

10 1 1 1
1 3 4 5 7 8 10 11 14 18
1
1
1


*/