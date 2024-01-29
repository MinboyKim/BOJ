#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int T, N;

void solve(string num) {
  for (int i = 0; i < (num.length() / 2); i++) {
    if (num[i] != num[num.length() - 1 - i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> N;
    string s = to_string(N);
    reverse(s.begin(), s.end());
    int temp = N + stoi(s);
    solve(to_string(temp));
  }

  return 0;
}