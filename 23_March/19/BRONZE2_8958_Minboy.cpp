#include <iostream>
#include <string>

using namespace std;

int T;
string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> s;
    int cnt = 1;
    int score = 0;
    for (auto &i : s) {
      if (i == 'O') {
        score += cnt;
        cnt++;
      } else
        cnt = 1;
    }
    cout << score << "\n";
  }
  return 0;
}