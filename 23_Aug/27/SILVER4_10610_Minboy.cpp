#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s;
int sum;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s;
  sort(s.begin(), s.end(), greater<char>());

  if (s[s.length() - 1] != '0') {
    cout << -1 << "\n";
    return 0;
  }
  for (int i = 0; i < s.length() - 1; i++) sum += s[i] - '0';
  if (sum % 3 == 0)
    cout << s << "\n";
  else
    cout << -1 << "\n";

  return 0;
}