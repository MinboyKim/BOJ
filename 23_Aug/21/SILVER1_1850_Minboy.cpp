#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

ull A, B;

ull euclid(ull a, ull b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  if (a % b == 0)
    return b;
  else
    return euclid(b, a % b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> B;

  string ans;
  for (int i = 0; i < euclid(A, B); i++) ans += "1";

  cout << ans << "\n";

  return 0;
}