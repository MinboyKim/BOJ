#include <bits/stdc++.h>

using namespace std;

int arr[303];
int n;
int dp[303];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
    }

    cout << dp[n];
}
