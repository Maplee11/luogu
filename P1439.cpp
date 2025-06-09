#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    // input
    vector<int> s(n), ss(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &ss[i]);
    }

    // reindex
    vector<int> rank(n+1);
    for (int i = 0; i < n; i++) {
        rank[ss[i]] = i + 1;
    }

    #define less(a, b) (rank[a] < rank[b])

    // len -> tailNum
    map<int, int> chains;
    chains[1] = s[0];

    for (int i = 1; i < n; i++) {
        int num = s[i];
        int key = 0;
        for (auto it = chains.rbegin(); it != chains.rend(); it++) {
            if (less(it->second, num)) {
                key = it->first;
                break;
            }
        }

        if (chains.find(key + 1) != chains.end()) {
            if (less(num, chains[key + 1])) {
                chains[key + 1] = num;
            }
        } else {
            chains[key + 1] = num;
        }
    }

    cout << prev(chains.end())->first << endl;

    return 0;
}
/* 

10
8 3 9 2 1 6 4 5 7 10
1 8 2 6 7 3 4 10 5 9

2 6 10 3 1 4 7 9 5 8


*/