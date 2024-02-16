#include <iostream>
#include <string>

using namespace std;

int ans;
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s;

  int i = 0;
  while (i < s.length()) {
    ans++;
    while (true) {
      int j = i;
      int k = i + 1;
      if (s[j] >= s[k]) break;
      i++;
    }
    i++;
  }

  cout << ans << "\n";

  return 0;
}