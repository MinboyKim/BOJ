#include <iostream>
#include <string>

using namespace std;

string s;
int ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string temp;
  for (int i = 0; i < 8; i++) {
    cin >> temp;
    s += temp;
    s += '.';
  }

  for (int i = 0; i < s.length(); i += 2)
    if (s[i] == 'F') ans++;

  cout << ans << "\n";

  return 0;
}