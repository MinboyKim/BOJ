#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int Arr[1111];
int dp[1111];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> Arr[i];

  for (int i = N - 1; i > 0; i--) {
    int temp = Arr[i];
    if (!temp) {
      dp[i] = 999'999'999;
      continue;
    }
    vector<int> temp2;
    bool flag = false;
    for (int j = 1; j <= temp; j++) {
      if (i + j >= N) {
        dp[i] = 1;
        flag = true;
        break;
      } else {
        temp2.push_back(dp[i + j]);
      }
    }
    if (flag || temp2.size() == 0) continue;
    sort(temp2.begin(), temp2.end());
    dp[i] = temp2[0] + 1;
  }

  cout << (dp[1] < 999'999'990 ? dp[1] : -1) << "\n";

  return 0;
}