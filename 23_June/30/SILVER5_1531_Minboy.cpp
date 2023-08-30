#include <iostream>

using namespace std;

int N, M, ans;
int Arr[111][111];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b, c, d;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c >> d;
    for (int j = a; j <= c; j++) {
      for (int k = b; k <= d; k++) {
        Arr[j][k]++;
      }
    }
  }

  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (Arr[i][j] > M) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}