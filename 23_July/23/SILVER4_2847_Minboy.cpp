#include <iostream>

using namespace std;

int N, ans;
int Arr[111];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i < N; i++) cin >> Arr[i];
  for (int i = N - 2; i >= 0; i--) {
    if (Arr[i] >= Arr[i + 1]) {
      ans += Arr[i] - (Arr[i + 1] - 1);
      Arr[i] = Arr[i + 1] - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}
