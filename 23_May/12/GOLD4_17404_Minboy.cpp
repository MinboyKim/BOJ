#include <iostream>

using namespace std;

int N, ans = 999'999'999;
int cost[1010][3];
int dp[1010][3];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 3; j++) cin >> cost[i][j];

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      if (i == j) continue;
      dp[1][i] = cost[0][j] + cost[1][i];
    }
    dp[2][j] = 9999999;
    for (int i = 0; i < 3; i++) {
      if (i == j) continue;
      if (dp[2][j] > dp[1][i] + cost[2][j]) dp[2][j] = dp[1][i] + cost[2][j];
    }
    for (int i = 0; i < 3; i++) {
      if (i == j) continue;
      for (int k = 0; k < 3; k++) {
        if (k == j || k == i) continue;
        dp[2][i] = dp[1][k] + cost[2][i];
      }
    }
    for (int i = 3; i < N; i++) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int temp = 999'999'999;
    for (int i = 0; i < 3; i++) {
      if (i == j) continue;
      temp = min(temp, dp[N - 1][i]);
    }
    ans = min(ans, temp);
  }

  cout << ans << "\n";

  return 0;
}