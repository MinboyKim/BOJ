#include <iostream>
#include <unordered_set>

using namespace std;

int R, C, ans;
char Arr[20][20];
int diff[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
int Visit[30];

void dfs(int d, int r, int c) {
  if (d > ans) ans = d;
  if (d >= R * C) return;
  for (int i = 0; i < 4; i++) {
    int rd = r + diff[0][i];
    int cd = c + diff[1][i];
    if (rd < 0 || cd < 0 || rd >= R || cd >= C) continue;
    if (!Visit[Arr[rd][cd] - 'A']) {
      Visit[Arr[rd][cd] - 'A'] = 1;
      dfs(d + 1, rd, cd);
      Visit[Arr[rd][cd] - 'A'] = 0;
    }
  }
}

int main(void) {
  cin.tie(NULL)->ios::sync_with_stdio(false);

  cin >> R >> C;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) cin >> Arr[i][j];

  ans++;
  Visit[Arr[0][0] - 'A'] = 1;
  dfs(1, 0, 0);

  cout << ans << "\n";

  return 0;
}