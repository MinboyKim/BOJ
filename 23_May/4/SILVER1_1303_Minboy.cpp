#include <cmath>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int N, M, blue, white;
char Arr[111][111];
int diff[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

int bfs(int row, int col, char party) {
  queue<pii> q;
  int ret = 0;
  q.push({row, col});
  Arr[row][col] = 'N';
  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();
    ret++;
    for (int i = 0; i < 4; i++) {
      int x = curX + diff[0][i];
      int y = curY + diff[1][i];
      if (x < 0 || y < 0 || x >= N || y >= M) continue;
      if (Arr[x][y] == party) {
        q.push({x, y});
        Arr[x][y] = 'N';
      }
    }
  }
  return ret;
}

int main(void) {
  cin.tie(0)->sync_with_stdio(0);

  cin >> M >> N;

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) Arr[i][j] = s[j];
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (Arr[i][j] == 'B')
        blue += pow(bfs(i, j, Arr[i][j]), 2);
      else if (Arr[i][j] == 'W')
        white += pow(bfs(i, j, Arr[i][j]), 2);
    }

  cout << white << " " << blue << "\n";

  return 0;
}