#include <algorithm>
#include <iostream>

using namespace std;

int N, C, W, height;
long long ans;
int Arr[55];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> C >> W;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
    height = max(height, Arr[i]);
  }

  for (int i = 1; i <= height; i++) {
    long long sum = 0;
    for (int j = 0; j < N; j++) {
      if (Arr[j] >= i) {
        int cnt = 0;
        int cost = 0;
        cnt += Arr[j] / i;
        cost += Arr[j] / i - 1;
        if (Arr[j] % i) cost++;
        if (cnt * i * W - cost * C > 0) sum += cnt * i * W - cost * C;
      }
    }
    ans = max(ans, sum);
  }

  cout << ans << "\n";

  return 0;
}