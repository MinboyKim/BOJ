#include <iostream>

using namespace std;

int n;
int dp[50'505];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}