#include <iostream>

using namespace std;

int n, ans;
int Arr[555][555];
int dp[555][555];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) cin >> Arr[i][j];

  dp[0][0] = Arr[0][0];
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= i; j++) {
      if (i - 1 >= 0 && j - 1 >= 0)
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + Arr[i][j];
      else
        dp[i][j] = dp[i - 1][j] + Arr[i][j];
    }

  for (int i = 0; i < n; i++) ans = max(ans, dp[n - 1][i]);
  cout << ans << "\n";

  return 0;
}