#include <iostream>

using namespace std;

int n, ans;
int Arr[1010];
int dp[1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Arr[i];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (Arr[i] > Arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}