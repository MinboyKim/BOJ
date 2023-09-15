#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll city[1010];
ll weather[1010];
ll dp[1010][1010];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> city[i];
        dp[i][0] = 999999999;
    }
    for (int j = 0; j < m; j++) {
        cin >> weather[j];
    }

    dp[0][0] = city[0] * weather[0];

    for (int i = 1; i < m; i++) {
        dp[0][i] = min(dp[0][i-1], (city[0] * weather[i]));
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] =
                min(dp[i][j - 1], dp[i - 1][j - 1] + city[i] * weather[j]);
        }
    }
    cout << dp[n - 1][m - 1];
}