#include <iostream>
#include <string>

using namespace std;

string Arr[55];
int N, M, ans;

void dfs(int r, int c, char type) {
  Arr[r][c] = '.';
  if (type == '-') {
    if (c - 1 >= 0 && Arr[r][c - 1] == type) dfs(r, c - 1, type);
    if (c + 1 < M && Arr[r][c + 1] == type) dfs(r, c + 1, type);
  } else if (type == '|') {
    if (type == '|') {
      if (r - 1 >= 0 && Arr[r - 1][c] == type) dfs(r - 1, c, type);
      if (r + 1 < N && Arr[r + 1][c] == type) dfs(r + 1, c, type);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> Arr[i];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (Arr[i][j] != '.') {
        ans++;
        dfs(i, j, Arr[i][j]);
      }

  cout << ans << "\n";

  return 0;
}