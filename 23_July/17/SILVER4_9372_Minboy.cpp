#include <iostream>

using namespace std;

int T, N, M;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> N >> M;
    int a, b;
    while (M--) cin >> a >> b;
    cout << N - 1 << "\n";
  }
  return 0;
}