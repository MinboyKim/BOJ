#include <cmath>
#include <iostream>
#include <string>

using namespace std;

long long ans;
int L, r = 31, M = 1234567891;
string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> L >> s;
  for (int i = 0; i < L; i++) {
    int a = s[i] - 'a' + 1;
    long long temp = 1;
    for (int j = 0; j < i; j++) temp = ((temp % M) * r) % M;
    ans += (a * (temp % M)) % M;
  }
  cout << ans % M << "\n";

  return 0;
}