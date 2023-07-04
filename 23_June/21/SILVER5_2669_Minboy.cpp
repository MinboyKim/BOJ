#include <iostream>

using namespace std;

int Arr[111][111];
int ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b, c, d;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b >> c >> d;
    for (int j = a; j < c; j++)
      for (int k = b; k < d; k++) Arr[j][k] = 1;
  }

  for (int i = 0; i < 111; i++) {
    for (int j = 0; j < 111; j++) {
      if (Arr[i][j]) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}