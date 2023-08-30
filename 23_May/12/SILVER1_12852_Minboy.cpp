#include <iostream>

using namespace std;

int N;
int dp[1'010'101];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;

  for (int i = 2; i <= N; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
  }

  cout << dp[N] << "\n";

  while (N != 1) {
    cout << N << " ";
    if (dp[N] - 1 == dp[N - 1])
      N = N - 1;
    else if (N % 3 == 0 && dp[N] - 1 == dp[N / 3])
      N = N / 3;
    else if (N % 2 == 0 && dp[N] - 1 == dp[N / 2])
      N = N / 2;
  }
  cout << 1 << "\n";

  return 0;
}