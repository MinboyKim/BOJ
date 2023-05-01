#include <algorithm>
#include <iostream>

using namespace std;

long long N, ans;
int Arr[101'010];

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  sort(Arr, Arr + N, greater<int>());

  for (int i = 0; i < N; i++)
    if (Arr[i] - i > 0) ans += Arr[i] - i;

  cout << ans << "\n";

  return 0;
}