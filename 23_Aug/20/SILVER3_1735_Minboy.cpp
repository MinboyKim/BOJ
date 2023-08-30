#include <algorithm>
#include <iostream>

using namespace std;

int a, b, c, d, son, mom;

int euclid(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  if (a % b == 0)
    return b;
  else
    return euclid(b, a % b);
}

int main() {
  cin >> a >> b >> c >> d;

  mom = b * d;
  son = a * (mom / b) + c * (mom / d);

  int gcd = euclid(mom, son);
  cout << son / gcd << " " << mom / gcd << "\n";

  return 0;
}