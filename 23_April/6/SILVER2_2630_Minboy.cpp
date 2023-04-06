#include <iostream>

using namespace std;

int N, white, blue;
int Arr[150][150];

bool check(int size, int r, int c) {
  int cmp = Arr[r][c];
  for (int i = r; i < r + size; i++)
    for (int j = c; j < c + size; j++)
      if (cmp != Arr[i][j]) return false;

  return true;
}

void dfs(int size, int r, int c) {
  int o = size / 2;
  if (check(size, r, c)) {
    if (Arr[r][c])
      blue++;
    else
      white++;
    return;
  } else {
    dfs(o, r, c);
    dfs(o, r + o, c);
    dfs(o, r, c + o);
    dfs(o, r + o, c + o);
  }
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> Arr[i][j];

  dfs(N, 0, 0);

  cout << white << "\n" << blue << "\n";

  return 0;
}