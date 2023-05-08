#include <algorithm>
#include <iostream>

using namespace std;

int N, M, ans, idx;
int Arr[1010];

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> Arr[i];

  sort(Arr, Arr + M);
  for (int i = 0; i < M; i++) {
    int tmp = 0;
    if (M - i >= N)
      tmp = Arr[i] * N;
    else
      tmp = Arr[i] * (M - i);
    if (tmp > ans) {
      ans = tmp;
      idx = i;
    }
  }

  cout << Arr[idx] << " " << ans << "\n";

  return 0;
}