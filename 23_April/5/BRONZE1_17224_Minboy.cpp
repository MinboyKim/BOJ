#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int N, L, K, cnt, ans;
pii Arr[111];

bool cmp(pii a, pii b) { return a.second < b.second; }

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> L >> K;
  for (int i = 0; i < N; i++) cin >> Arr[i].first >> Arr[i].second;

  sort(Arr, Arr + N, cmp);
  for (int i = 0; i < N; i++) {
    if (cnt >= K) break;
    if (L >= Arr[i].second) {
      cnt++;
      ans += 140;
    }
  }
  sort(Arr, Arr + N);
  for (int i = 0; i < N; i++) {
    if (cnt >= K) break;
    if (L >= Arr[i].first && L < Arr[i].second) {
      cnt++;
      ans += 100;
    }
  }

  cout << ans << "\n";

  return 0;
}