#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef struct {
  int r;
  int c;
  int cnt;
} cod;

int N, M;
int Arr[111][111];
int Visit[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
queue<cod> q;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) Arr[i][j] = s[j] - '0';
  }

  q.push({0, 0, 1});
  Visit[0][0] = 1;
  while (!q.empty()) {
    cod cur = q.front();
    q.pop();
    if (cur.r == N - 1 && cur.c == M - 1) {
      cout << cur.cnt << "\n";
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int nextR = cur.r + diff[0][i];
      int nextC = cur.c + diff[1][i];
      if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M ||
          !Arr[nextR][nextC] || Visit[nextR][nextC])
        continue;
      Visit[nextR][nextC] = 1;
      q.push({nextR, nextC, cur.cnt + 1});
    }
  }

  return 0;
}