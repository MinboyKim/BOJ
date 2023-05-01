#include <iostream>

using namespace std;

long long x, y, ans = 1;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> x >> y;
  if (y == 0) {
    for (int i = 1; i <= x; i++) ans += 6 * i;
  } else {
    for (int i = 1; i <= x + y - 1; i++) ans += 6 * i;
    ans += y;
  }

  cout << ans << "\n";

  return 0;
}