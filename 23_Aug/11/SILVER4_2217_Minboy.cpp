#include <algorithm>
#include <iostream>

using namespace std;

int N, ans;
int Arr[101'010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  sort(Arr, Arr + N);

  for (int i = 0; i < N; i++) ans = max(ans, Arr[i] * (N - i));

  cout << ans << "\n";

  return 0;
}