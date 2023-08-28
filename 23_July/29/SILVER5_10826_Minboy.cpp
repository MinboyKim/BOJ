#include <iostream>

using namespace std;

int n;
long long dp[10'101];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= n; i++) dp[i] = dp[i - 2] + dp[i - 1];

  cout << dp[n] << "\n";

  return 0;
}