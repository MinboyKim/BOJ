#include <iostream>

using namespace std;

typedef unsigned long long ull;

int N;
ull dp[1'000'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= N; i++) {

        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    }

    cout << dp[N] << "\n";

    return 0;
}