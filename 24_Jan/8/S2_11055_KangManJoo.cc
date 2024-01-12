#include <bits/stdc++.h>

using namespace std;

long long arr[1010];
long long dp[1010];

long long MAX;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
            MAX = max(MAX, dp[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] > MAX)
            MAX = dp[i];
    }
    cout << MAX;
}