#include <iostream>

using namespace std;

int n, m, ansCnt, ansArea;
int Arr[555][555];
int diff[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

int dfs(int row, int col) {
  int ret = 1;
  Arr[row][col] = 0;

  for (int i = 0; i < 4; i++) {
    int x = row + diff[0][i];
    int y = col + diff[1][i];
    if (x < 0 || y < 0 || x >= n || y >= m) continue;
    if (Arr[x][y]) ret += dfs(x, y);
  }
  return ret;
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> Arr[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (Arr[i][j]) {
        ansCnt++;
        ansArea = max(ansArea, dfs(i, j));
      }
    }

  cout << ansCnt << "\n" << ansArea << "\n";

  return 0;
}