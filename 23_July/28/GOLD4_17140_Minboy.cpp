#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int Arr[111][111];
int cnt[111];
int r, c, k, ans, rSize = 3, cSize = 3;

bool compare(pii a, pii b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

void rop() {
  int maxSize = 0;
  for (int i = 1; i <= rSize; i++) {
    vector<pii> v;
    for (int j = 1; j <= 105; j++) cnt[j] = 0;
    for (int j = 1; j <= cSize; j++) cnt[Arr[i][j]]++;
    for (int j = 1; j < 105; j++) {
      if (!cnt[j]) continue;
      v.push_back({j, cnt[j]});
    }
    sort(v.begin(), v.end(), compare);
    for (int j = 1; j <= cSize; j++) Arr[i][j] = 0;
    int idx = 1;
    for (auto &j : v) {
      Arr[i][idx++] = j.first;
      Arr[i][idx++] = j.second;
    }
    maxSize = max(maxSize, (int)v.size() * 2);
  }
  cSize = maxSize;
}

void cop() {
  int maxSize = 0;
  for (int i = 1; i <= cSize; i++) {
    vector<pii> v;
    for (int j = 1; j <= 105; j++) cnt[j] = 0;
    for (int j = 1; j <= rSize; j++) cnt[Arr[j][i]]++;
    for (int j = 1; j < 105; j++) {
      if (!cnt[j]) continue;
      v.push_back({j, cnt[j]});
    }
    sort(v.begin(), v.end(), compare);
    for (int j = 1; j <= rSize; j++) Arr[j][i] = 0;
    int idx = 1;
    for (auto &j : v) {
      Arr[idx++][i] = j.first;
      Arr[idx++][i] = j.second;
    }
    maxSize = max(maxSize, (int)v.size() * 2);
  }
  rSize = maxSize;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> r >> c >> k;
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) cin >> Arr[i][j];

  while (ans <= 100) {
    if (Arr[r][c] == k) {
      cout << ans << "\n";
      return 0;
    }
    if (rSize >= cSize)
      rop();
    else
      cop();
    ans++;
  }

  cout << -1 << "\n";

  return 0;
}