#include <algorithm>
#include <iostream>

using namespace std;

int N;
int Arr[333];
int dp[333];

int main(void) {
  cin.tie(0)->ios::sync_with_stdio(0);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> Arr[i];

  dp[1] = Arr[1];
  dp[2] = Arr[2] + Arr[1];
  for (int i = 3; i <= N; i++)
    dp[i] = max(dp[i - 3] + Arr[i - 1] + Arr[i], dp[i - 2] + Arr[i]);
  cout << dp[N] << "\n";
  return 0;
}