#include <iostream>
#include <string>

using namespace std;

int N;
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  while (N--) {
    cin >> s;
    cout << (s[s.length() / 2 - 1] == s[s.length() / 2] ? "Do-it" : "Do-it-Not")
         << "\n";
  }

  return 0;
}