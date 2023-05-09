#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int N, dir, xMin = 55, xMax = 55, yMin = 55, yMax = 55;
string cmd;
int Arr[111][111];
int diff[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};  // 남, 동, 북, 서
pii pos;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  Arr[55][55] = 1;
  pos = {55, 55};
  cin >> cmd;

  for (int i = 0; i < N; i++) {
    if (cmd[i] == 'L')
      dir = (dir + 1) % 4;
    else if (cmd[i] == 'R') {
      dir -= 1;
      if (dir == -1) dir = 3;
    } else {
      pos.first += diff[0][dir];
      pos.second += diff[1][dir];
      if (!Arr[pos.first][pos.second]) {
        Arr[pos.first][pos.second] = 1;
        if (pos.first > xMax)
          xMax = pos.first;
        else if (pos.first < xMin)
          xMin = pos.first;
        else if (pos.second > yMax)
          yMax = pos.second;
        else if (pos.second < yMin)
          yMin = pos.second;
      }
    }
  }

  for (int i = yMin; i <= yMax; i++) {
    for (int j = xMin; j <= xMax; j++) {
      if (!Arr[j][i])
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }

  return 0;
}