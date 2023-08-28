#include <iostream>

using namespace std;

int n;
int dp[101'010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  dp[1] = -1;
  dp[2] = 1;
  dp[3] = -1;
  dp[4] = 2;
  dp[5] = 1;
  dp[6] = 3;
  dp[7] = 2;
  dp[8] = 4;
  for (int i = 9; i <= n; i++) {
    dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
  }
  cout << dp[n] << "\n";

  return 0;
}