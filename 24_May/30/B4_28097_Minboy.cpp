#include <iostream>

using namespace std;

int N, ans, T;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> T;
    ans += T;
  }
  ans += (N - 1) * 8;

  cout << ans / 24 << " " << ans % 24 << "\n";

  return 0;
}
