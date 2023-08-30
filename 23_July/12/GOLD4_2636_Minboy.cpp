#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, ans, cnt;
int Arr[111][111];
int Visit[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> Arr[i][j];
      if (Arr[i][j]) cnt++;
    }
  }

  while (true) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) Visit[i][j] = 0;
    queue<pii> q;
    Visit[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
      pii cur = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = cur.first + diff[0][i];
        int ny = cur.second + diff[1][i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (!Visit[nx][ny]) {
          Visit[nx][ny] = 1;
          if (Arr[nx][ny] == 0)
            q.push({nx, ny});
          else
            Arr[nx][ny] = 0;
        }
      }
    }
    int flag = false;
    int temp = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (Arr[i][j]) {
          temp++;
          flag = true;
        }
      }
    }
    if (!flag) {
      cout << ans + 1 << "\n" << cnt << "\n";
      return 0;
    }
    ans++;
    cnt = temp;
  }

  return 0;
}