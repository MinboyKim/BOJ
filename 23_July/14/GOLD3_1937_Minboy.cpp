#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int Arr[555][555];
int dp[555][555];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

int dfs(int x, int y) {
  if (dp[x][y]) return dp[x][y];
  dp[x][y] = 1;

  for (int i = 0; i < 4; i++) {
    int nx = x + diff[0][i];
    int ny = y + diff[1][i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (Arr[x][y] < Arr[nx][ny]) {
      dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
  }
  return dp[x][y];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> Arr[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans = max(ans, dfs(i, j));

  cout << ans << "\n";

  return 0;
}