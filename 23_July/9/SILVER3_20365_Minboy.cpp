#include <iostream>
#include <string>

using namespace std;

int N, bCnt, rCnt;
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> s;
  int i = 0;
  while (i < N) {
    if (s[i] == 'B') {
      bCnt++;
      while (s[i] == 'B') i++;
    } else {
      rCnt++;
      while (s[i] == 'R') i++;
    }
  }

  cout << min(bCnt, rCnt) + 1 << "\n";

  return 0;
}