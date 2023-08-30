#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

int board[101][101];

int main() {
  cin >> n >> m;
  int lx, ly, rx, ry;
  while (n--) {
    cin >> lx >> ly >> rx >> ry;
    for (int i = lx; i <= rx; i++) {
      for (int j = ly; j <= ry; j++) {
        board[i][j]++;
      }
    }
  }

  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (board[i][j] > m) {
        cnt++;
      }
    }
  }

  cout << cnt;
}