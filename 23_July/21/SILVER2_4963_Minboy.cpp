#include <iostream>

using namespace std;

int w, h, ans;
int Arr[55][55];
int diff[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1, -1, -1}};

void dfs(int r, int c) {
  Arr[r][c] = -1;
  for (int i = 0; i < 8; i++) {
    int nr = r + diff[0][i];
    int nc = c + diff[1][i];
    if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
    if (Arr[nr][nc] == 1) dfs(nr, nc);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  while (true) {
    cin >> w >> h;
    if (!w && !h) break;
    ans = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) Arr[h][w] = 0;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) cin >> Arr[i][j];

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (Arr[i][j] == 1) {
          ans++;
          dfs(i, j);
        }

    cout << ans << "\n";
  }

  return 0;
}