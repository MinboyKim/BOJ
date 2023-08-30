#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N, M;
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  while (N--) {
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << "\n";
  }

  return 0;
}
