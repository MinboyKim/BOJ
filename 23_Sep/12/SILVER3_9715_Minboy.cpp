#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int T, R, C, ans;
int Arr[55][55];
string s;

int my_up_down() {
  int ret = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (Arr[i][j]) ret++;
  return ret * 2;
}

int my_right() {
  int ret = 0;
  for (int i = C - 1; i >= 0; i--) {
    int temp = 0;
    for (int j = R - 1; j >= 0; j--) {
      if (Arr[j][i] > temp) ret += Arr[j][i] - temp;
      temp = Arr[j][i];
    }
  }
  return ret;
}

int my_left() {
  int ret = 0;
  for (int i = 0; i < R; i++) {
    int temp = 0;
    for (int j = 0; j < C; j++) {
      if (Arr[i][j] > temp) ret += Arr[i][j] - temp;
      temp = Arr[i][j];
    }
  }
  return ret;
}

int my_front() {
  int ret = 0;
  for (int i = 0; i < R; i++) {
    int temp = 0;
    for (int j = C - 1; j >= 0; j--) {
      if (Arr[i][j] > temp) ret += Arr[i][j] - temp;
      temp = Arr[i][j];
    }
  }
  return ret;
}

int my_back() {
  int ret = 0;
  for (int i = 0; i < C; i++) {
    int temp = 0;
    for (int j = 0; j < R; j++) {
      if (Arr[j][i] > temp) ret += Arr[j][i] - temp;
      temp = Arr[j][i];
    }
  }
  return ret;
}

void solve() {
  ans = 0;
  ans += my_up_down();
  ans += my_right();
  ans += my_left();
  ans += my_front();
  ans += my_back();
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
      cin >> s;
      for (int j = 0; j < C; j++) Arr[i][j] = s[j] - '0';
    }
    solve();
  }

  return 0;
}