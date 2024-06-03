#include <iostream>

using namespace std;

int N;
int dp[1111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    dp[2] = 1;
    for (int i = 4; i <= N; i++)
        if (dp[i - 3] == 0 || dp[i - 1] == 0) dp[i] = 1;

    cout << (dp[N] == 1 ? "SK\n" : "CY\n");

    return 0;
}