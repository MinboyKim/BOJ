#include <iostream>

using namespace std;

int Arr[55][55];
int N, M, dir, curR, curC, ans;
int diff[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};

bool findDirt() {
  for (int i = 0; i < 4; i++) {
    int nextR = curR + diff[0][i];
    int nextC = curC + diff[1][i];
    if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
    if (!Arr[nextR][nextC]) return true;
  }
  return false;
}

bool backward() {
  int nextR = curR - diff[0][dir];
  int nextC = curC - diff[1][dir];
  if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) return false;
  if (Arr[nextR][nextC] != 1) {
    curR = nextR;
    curC = nextC;
    return false;
  }
  return true;
}

void forward() {
  for (int i = 1; i < 5; i++) {
    dir = dir - 1;
    if (dir < 0) dir = 3;
    int nextR = curR + diff[0][dir];
    int nextC = curC + diff[1][dir];
    if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
    if (!Arr[nextR][nextC]) {
      curR = nextR;
      curC = nextC;
      return;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M >> curR >> curC >> dir;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> Arr[i][j];

  while (true) {
    if (!Arr[curR][curC]) {
      Arr[curR][curC] = 2;
      ans++;
    }
    bool isDirt = false;
    bool term = false;
    isDirt = findDirt();
    if (!isDirt)
      term = backward();
    else
      forward();
    if (term) break;
  }

  cout << ans << "\n";

  return 0;
}