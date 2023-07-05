#include <iostream>

using namespace std;

long long dp[111];
int N;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  dp[3] = 5;
  dp[4] = 8;
  for (int i = 5; i <= N; i++) dp[i] = dp[i - 2] + dp[i - 1];
  if (N <= 2)
    cout << 1 << "\n";
  else if (N == 3)
    cout << 2 << "\n";
  else if (N == 4)
    cout << 3 << "\n";
  else
    cout << dp[N - 2] << "\n";
  return 0;
}