#include <iostream>

using namespace std;

int T, M, N, K, ans;
int Arr[55][55];
int Visit[55][55];
int diff[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void dfs(int r, int c) {
  Visit[r][c] = 1;
  for (int i = 0; i < 4; i++) {
    int dr = r + diff[0][i];
    int dc = c + diff[1][i];
    if (dr < 0 || dc < 0 || dr >= M || dc >= N) continue;
    if (!Visit[dr][dc] && Arr[dr][dc]) {
      dfs(dr, dc);
    }
  }
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++) {
        Arr[i][j] = 0;
        Visit[i][j] = 0;
      }
    int X, Y;
    for (int i = 0; i < K; i++) {
      cin >> X >> Y;
      Arr[X][Y] = 1;
    }
    ans = 0;
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++) {
        if (!Visit[i][j] && Arr[i][j]) {
          ans++;
          dfs(i, j);
        }
      }
    cout << ans << "\n";
  }

  return 0;
}