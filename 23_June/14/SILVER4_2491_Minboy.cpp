#include <iostream>

using namespace std;

int N, ans = 1;
int Arr[101'010];
int dp1[101'010];
int dp2[101'010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
    if (i == 0) {
      dp1[i] = 1;
      dp2[i] = 1;
      continue;
    }
    if (Arr[i - 1] <= Arr[i]) {
      dp1[i] = dp1[i - 1] + 1;
      ans = max(ans, dp1[i]);
    } else
      dp1[i] = 1;
    if (Arr[i - 1] >= Arr[i]) {
      dp2[i] = dp2[i - 1] + 1;
      ans = max(ans, dp2[i]);
    } else
      dp2[i] = 1;
  }

  cout << ans << "\n";

  return 0;
}