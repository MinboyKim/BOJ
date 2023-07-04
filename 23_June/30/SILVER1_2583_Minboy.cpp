#include <iostream>
#include <vector>

using namespace std;

int M, N, K;
int Arr[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
vector<int> ans;

int dfs(int r, int c) {
  int ret = 1;
  Arr[r][c] = 1;
  for (int i = 0; i < 4; i++) {
    int nr = r + diff[0][i];
    int nc = c + diff[1][i];
    if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
    if (!Arr[nr][nc]) ret += dfs(nr, nc);
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> M >> N >> K;
  int a, b, c, d;
  for (int i = 0; i < K; i++) {
    cin >> a >> b >> c >> d;
    for (int j = a; j < c; j++) {
      for (int k = b; k < d; k++) {
        Arr[j][k] = 1;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) cout << Arr[i][j] << " ";
    cout << "\n";
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!Arr[i][j]) ans.push_back(dfs(i, j));
    }
  }

  for (auto &i : ans) cout << i << " ";

  return 0;
}