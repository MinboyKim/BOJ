#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int Arr[55][55], sumArr[55][55];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
int R, C, T, ans;
vector<pii> cleaner;

void init() {
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) sumArr[i][j] = 0;
}

void spread() {
  init();
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (Arr[i][j] != -1 && Arr[i][j]) {
        int amt = Arr[i][j] / 5;
        for (int k = 0; k < 4; k++) {
          int nr = i + diff[0][k];
          int nc = j + diff[1][k];
          if (nr < 0 || nc < 0 || nr >= R || nc >= C || Arr[nr][nc] == -1)
            continue;
          sumArr[nr][nc] += amt;
          Arr[i][j] -= amt;
        }
      }

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) Arr[i][j] += sumArr[i][j];
}

void uploop() {
  int cr = cleaner[0].first;
  int cc = cleaner[0].second;

  for (int i = cr - 1; i >= 1; i--) Arr[i][cc] = Arr[i - 1][cc];
  for (int i = cc; i < C - 1; i++) Arr[0][i] = Arr[0][i + 1];
  for (int i = 0; i <= cr - 1; i++) Arr[i][C - 1] = Arr[i + 1][C - 1];
  for (int i = C - 1; i > cc + 1; i--) Arr[cr][i] = Arr[cr][i - 1];
  Arr[cr][cc + 1] = 0;
}

void downloop() {
  int cr = cleaner[1].first;
  int cc = cleaner[1].second;

  for (int i = cr + 1; i < R - 1; i++) Arr[i][cc] = Arr[i + 1][cc];
  for (int i = cc; i < C - 1; i++) Arr[R - 1][i] = Arr[R - 1][i + 1];
  for (int i = R - 1; i >= cr + 1; i--) Arr[i][C - 1] = Arr[i - 1][C - 1];
  for (int i = C - 1; i > cc + 1; i--) Arr[cr][i] = Arr[cr][i - 1];
  Arr[cr][cc + 1] = 0;
}

void loop() {
  spread();
  uploop();
  downloop();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> R >> C >> T;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      cin >> Arr[i][j];
      if (Arr[i][j] == -1) cleaner.push_back({i, j});
    }

  while (T--) loop();

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (Arr[i][j] != -1) ans += Arr[i][j];

  cout << ans << "\n";

  return 0;
}