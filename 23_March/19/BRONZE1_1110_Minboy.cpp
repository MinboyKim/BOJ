#include <iostream>

using namespace std;

int N, ans;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int src = N;

  while (true) {
    if (N < 10) {
      N *= 11;
      ans++;
    } else {
      int tmp = (N / 10) + (N % 10);
      N = (N % 10 * 10) + (tmp % 10);
      ans++;
    }
    if (N == src) break;
  }
  cout << ans << "\n";

  return 0;
}