#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N;
int Arr[111][111];
int Visit[111][111];
queue<pii> q;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> Arr[i][j];
    }
  }

  q.push({1, 1});
  Visit[1][1] = 1;
  while (!q.empty()) {
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();

    int nextR = curR + Arr[curR][curC];
    int nextC = curC;
    if (nextR >= 1 && nextC >= 1 && nextR <= N && nextC <= N &&
        !Visit[nextR][nextC]) {
      if (Arr[nextR][nextC] == -1) {
        cout << "HaruHaru\n";
        return 0;
      }
      Visit[nextR][nextC] = 1;
      q.push({nextR, nextC});
    }

    nextR = curR;
    nextC = curC + Arr[curR][curC];
    if (nextR >= 1 && nextC >= 1 && nextR <= N && nextC <= N &&
        !Visit[nextR][nextC]) {
      if (Arr[nextR][nextC] == -1) {
        cout << "HaruHaru\n";
        return 0;
      }
      Visit[nextR][nextC] = 1;
      q.push({nextR, nextC});
    }
  }

  cout << "Hing\n";

  return 0;
}