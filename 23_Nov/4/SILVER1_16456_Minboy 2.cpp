#include <iostream>
#define MOD 1'000'000'009;

using namespace std;

int n;
long long dp[50'505];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n; i++)
        dp[i] = (dp[i - 3] + dp[i - 1]) % MOD;

    cout << dp[n] << "\n";

    return 0;
}