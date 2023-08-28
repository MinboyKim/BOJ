#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  while (true) {
    getline(cin, s);
    if (s == "END") break;
    reverse(s.begin(), s.end());
    cout << s << "\n";
  }

  return 0;
}