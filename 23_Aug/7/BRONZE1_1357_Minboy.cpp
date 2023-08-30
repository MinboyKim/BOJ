#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string X, Y, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> X >> Y;
  reverse(X.begin(), X.end());
  reverse(Y.begin(), Y.end());
  ans = to_string(stoi(X) + stoi(Y));
  reverse(ans.begin(), ans.end());
  cout << stoi(ans) << "\n";

  return 0;
}