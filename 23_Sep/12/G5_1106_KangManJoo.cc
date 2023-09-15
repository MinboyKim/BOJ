#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii cList[21];
int dp[100100];

// 무게 , 가치

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    int goal, n;
    cin >> goal >> n;

    for (int i = 0; i < n; i++) {
        cin >> cList[i].first >> cList[i].second;
    }

    // 3, 5
    for (int i = 0; i < n; i++) {
        int weight = cList[i].first;
        int cost = cList[i].second;

        for (int j = 1; j < 100001; j++) {
            if (j < weight)
                continue;
            dp[j] = max(dp[j], cost + dp[j - weight]);
        }
    }

    for (int i = 0; i < 100001; i++) {
        if (dp[i] >= goal) {
            cout << i;
            break;
        }
    }
    return 0;
}