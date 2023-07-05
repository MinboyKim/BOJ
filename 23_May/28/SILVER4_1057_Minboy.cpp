#include <iostream>

using namespace std;

int N, jm, hs, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> jm >> hs;

  while (jm != hs) {
    jm = (jm + 1) / 2;
    hs = (hs + 1) / 2;
    ans++;
  }
  cout << ans << "\n";

  return 0;
}
