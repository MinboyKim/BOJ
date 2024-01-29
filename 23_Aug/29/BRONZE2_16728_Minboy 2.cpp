#include <cmath>
#include <iostream>

using namespace std;

int N, x, y, ans;

int solve(int x, int y) {
  double dist = sqrt(pow(x, 2) + pow(y, 2));
  if (dist <= 10)
    return 10;
  else if (dist <= 30)
    return 9;
  else if (dist <= 50)
    return 8;
  else if (dist <= 70)
    return 7;
  else if (dist <= 90)
    return 6;
  else if (dist <= 110)
    return 5;
  else if (dist <= 130)
    return 4;
  else if (dist <= 150)
    return 3;
  else if (dist <= 170)
    return 2;
  else if (dist <= 190)
    return 1;
  else
    return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  while (N--) {
    cin >> x >> y;
    ans += solve(x, y);
  }

  cout << ans << "\n";

  return 0;
}