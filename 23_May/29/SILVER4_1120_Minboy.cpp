#include <iostream>
#include <string>

using namespace std;

string A, B;
int ans = 9999;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> B;

  for (int i = 0; i < B.length() - A.length() + 1; i++) {
    int cnt = 0;
    for (int j = 0; j < A.length(); j++)
      if (A[j] != B[i + j]) cnt++;
    ans = min(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}