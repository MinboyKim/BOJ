#include <iostream>

using namespace std;

int N, M, Sum, ans, l, r;
int Arr[10'101];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> Arr[i];

  while (true) {
    Sum = 0;
    for (int i = l; i <= r; i++) Sum += Arr[i];
    if (Sum == M) {
      ans++;
      if (r < N - 1)
        r++;
      else
        break;
    } else if (Sum > M && l < N - 1)
      l++;
    else if (Sum < M && r < N - 1)
      r++;
    else
      break;
  }

  cout << ans << "\n ";

  return 0;
}