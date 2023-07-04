#include <iostream>
#include <string>

using namespace std;

string s;
int zero, one;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      zero++;
      while (s[i] == '0') i++;
    }
  }

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      one++;
      while (s[i] == '1') i++;
    }
  }

  cout << ((zero < one) ? zero : one) << "\n";

  return 0;
}