#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if (b % d == 0) {
    b = b / d;
  } else {
    b = b / d + 1;
  }

  if (c % e == 0) {
    c = c / e;
  } else {
    c = c / e + 1;
  }

  int m = max(b, c);

  cout << a - m;
}