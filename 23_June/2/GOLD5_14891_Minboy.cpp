#include <deque>
#include <iostream>
#include <string>

using namespace std;

string gear[4];
int K, ans;
int dir[4];

void cw(int id) {
  char temp = gear[id][gear[id].length() - 1];
  gear[id] = gear[id].substr(0, gear[id].length() - 1);
  gear[id] = temp + gear[id];
}

void ccw(int id) {
  char temp = gear[id][0];
  gear[id] = gear[id].substr(1, gear[id].length() - 1);
  gear[id] += temp;
}

void solve(int a, int b) {
  for (int i = 0; i < 4; i++) dir[i] = 0;
  dir[a] = b;
  for (int i = a; i >= 1; i--) {
    if (gear[i][6] == gear[i - 1][2]) break;
    dir[i - 1] = ((dir[i] == 1) ? -1 : 1);
  }
  for (int i = a; i < 3; i++) {
    if (gear[i][2] == gear[i + 1][6]) break;
    dir[i + 1] = ((dir[i] == 1) ? -1 : 1);
  }
  for (int i = 0; i < 4; i++) {
    if (dir[i] == 1)
      cw(i);
    else if (dir[i] == -1)
      ccw(i);
  }
}

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> gear[i];
  }

  cin >> K;
  int a, b;
  while (K--) {
    cin >> a >> b;
    solve(a - 1, b);
  }

  for (int i = 0; i < 4; i++) {
    if (gear[i][0] == '1') ans += 1 << i;
  }

  cout << ans << "\n";

  return 0;
}