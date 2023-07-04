#include <algorithm>
#include <iostream>

using namespace std;

int Arr[55][55];
int N, ans;
char temp;
int diff[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void check() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cnt = 0;
      int ni = i;
      int nj = j;
      while (true) {
        if (ni < 0 || ni >= N) break;
        if (Arr[i][j] == Arr[ni][nj])
          cnt++;
        else
          break;
        ni++;
      }
      ans = max(ans, cnt);
      cnt = 0;
      ni = i;
      while (true) {
        if (nj < 0 || nj >= N) break;
        if (Arr[i][j] == Arr[ni][nj])
          cnt++;
        else
          break;
        nj++;
      }
      ans = max(ans, cnt);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> temp;
      if (temp == 'C')
        Arr[i][j] = 1;
      else if (temp == 'P')
        Arr[i][j] = 2;
      else if (temp == 'Z')
        Arr[i][j] = 3;
      else
        Arr[i][j] = 4;
    }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < 4; k++) {
        int ni = i + diff[0][k];
        int nj = j + diff[1][k];
        if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
        swap(Arr[i][j], Arr[ni][nj]);
        check();
        swap(Arr[i][j], Arr[ni][nj]);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}