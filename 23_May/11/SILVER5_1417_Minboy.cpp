#include <iostream>

using namespace std;

int N, ans, Max, maxIndex;
int Arr[55];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  while (1) {
    Max = 0;
    for (int i = 1; i < N; i++) {
      if (Max < Arr[i]) {
        Max = Arr[i];
        maxIndex = i;
      }
    }
    if (Max < Arr[0]) {
      cout << ans << "\n";
      return 0;
    }
    Arr[maxIndex]--;
    Arr[0]++;
    ans++;
  }
  return 0;
}