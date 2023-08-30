#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef struct {
  int row;
  int col;
  int dist;
} pos;

int N, M, ans;
int Arr[55][55];
int diff[2][8] = {{0, 0, -1, 1, -1, -1, 1, 1}, {-1, 1, 0, 0, -1, 1, -1, 1}};

void bfs(int r, int c) {
  queue<pos> q;
  int Visit[55][55];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) Visit[i][j] = 0;

  Visit[r][c] = 1;
  q.push({r, c, 0});
  while (!q.empty()) {
    pos cur = q.front();
    q.pop();
    if (Arr[cur.row][cur.col]) {
      ans = max(ans, cur.dist);
      return;
    }
    for (int i = 0; i < 8; i++) {
      int nextR = cur.row + diff[0][i];
      int nextC = cur.col + diff[1][i];
      if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
      if (!Visit[nextR][nextC]) {
        Visit[nextR][nextC] = 1;
        q.push({nextR, nextC, cur.dist + 1});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> Arr[i][j];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) bfs(i, j);

  cout << ans << "\n";

  return 0;
}