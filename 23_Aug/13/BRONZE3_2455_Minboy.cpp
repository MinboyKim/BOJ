#include <iostream>

using namespace std;

int ans, train;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b;
    train += b;
    train -= a;
    ans = max(ans, train);
  }

  cout << ans << "\n";

  return 0;
}