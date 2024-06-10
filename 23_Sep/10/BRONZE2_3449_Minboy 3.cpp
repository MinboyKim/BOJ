#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int T;
string a, b;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> a >> b;
    int size = a.length();
    ll c = stoll(a, 0, 2);
    ll d = stoll(b, 0, 2);
    c ^= d;

    int ans = 0;
    for (int i = 0; i < size; i++) ans += (c >> i) & 1;
    cout << "Hamming distance is " << ans << ".\n";
  }

  return 0;
}