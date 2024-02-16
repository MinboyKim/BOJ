#include <iostream>
#define MOD 1'000'000'009;

using namespace std;

int n, m, T;
long long dp[1111][1111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[2][2] = 1;
    dp[2][3] = 2;
    dp[3][3] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 4; j <= 1000; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j - 2] + dp[i - 1][j - 3]) % MOD;
        }
    }

    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << dp[m][n] << "\n";
    }

    return 0;
}