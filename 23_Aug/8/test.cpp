#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
int dp[10'101];
set<int> s;
vector<int> v;

int solve(int i) {
  int minValue = 999'999'999;
  bool flag = false;
  for (auto &j : v)
    if (minValue > dp[i - j] && dp[i - j] != -1) {
      minValue = dp[i - j];
      flag = true;
    }
  if (!flag) return -1;
  return minValue + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> k;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s.insert(a);
  }

  for (int i = 1; i <= k; i++) {
    for (auto &j : s) {
      if (j > i) break;
      if (j == i) v.push_back(j);
    }

    if (v.size() == 0)
      dp[i] = -1;
    else
      dp[i] = solve(i);
  }

  cout << dp[k] << "\n";

  return 0;
}