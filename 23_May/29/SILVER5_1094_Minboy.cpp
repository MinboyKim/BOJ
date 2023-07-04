#include <iostream>

using namespace std;

int X, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> X;

  while (X > 0) {
    int temp = 1;
    while (temp <= X) temp *= 2;
    temp /= 2;
    ans++;
    X -= temp;
  }

  cout << ans << "\n";

  return 0;
}