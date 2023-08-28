#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int n, m, ans;
int Arr[1111][1111];
int dp[1111][1111];

int solve(int r, int c) {
  int ret = 999'999'999;
  ret = min(ret, dp[r - 1][c - 1]);
  ret = min(ret, dp[r - 1][c]);
  ret = min(ret, dp[r][c - 1]);
  return ret + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) Arr[i][j] = s[j] - '0';
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!Arr[i][j]) continue;
      if (i <= 0 || j <= 0)
        dp[i][j] = 1;
      else
        dp[i][j] = solve(i, j);
      ans = max(ans, dp[i][j]);
    }
  }

  cout << pow(ans, 2) << "\n";

  return 0;
}