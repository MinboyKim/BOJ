#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull T, a, b;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> a >> b;
    ull temp = 1;
    for (int i = 0; i < b; i++) temp = temp * a % 10;
    if (temp % 10 == 0)
      cout << 10 << "\n";
    else
      cout << temp % 10 << "\n";
  }

  return 0;
}