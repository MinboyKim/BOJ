#include <iostream>

using namespace std;

int x, k, one, two, three;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> x >> k;

  x *= 1000;
  k *= 1000;

  one = 7 * k;
  two = 3 * k + (k / 2);
  three = k + (k / 4 * 3);
  if (one <= x)
    cout << one << "\n";
  else if (two <= x)
    cout << two << "\n";
  else if (three <= x)
    cout << three << "\n";
  else
    cout << 0 << "\n";

  return 0;
}