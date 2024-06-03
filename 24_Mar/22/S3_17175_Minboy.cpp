#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull n, dp[55];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1] + 1) % 1000000007;

    cout << dp[n] << "\n";

    return 0;
}