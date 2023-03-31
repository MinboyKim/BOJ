#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string s;
ll N;

int main(void) {
  cin.tie(NULL)->ios::sync_with_stdio(false);

  cin >> s;
  N = stoll(s);
  ll start = N - 9 * s.length();
  for (ll i = start; i <= N; i++) {
    ll tmp = i;
    ll sum = i;
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (sum == N) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";

  return 0;
}