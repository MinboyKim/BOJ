#include <cstring>
#include <iostream>

using namespace std;

int T, N, M;
int dp[33][33];

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < 30; i++) memset(dp[i], 0, sizeof(int) * 30);
    for (int i = 1; i <= M; i++) dp[1][i] = i;
    for (int i = 2; i <= N; i++) {
      for (int j = 1; j <= M; j++)
        for (int k = 1; k < j; k++) dp[i][j] += dp[i - 1][k];
    }
    cout << dp[N][M] << "\n";
  }

  return 0;
}