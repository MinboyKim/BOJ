#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, K;
long long ans;
pii gem[303'030];
int bag[303'030];

priority_queue<pii, vector<pii>> pq;

bool comp(pii a, pii b) { return a.second < b.second; }

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> K;
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    gem[i] = {b, a};
  }
  for (int i = 0; i < K; i++) cin >> bag[i];
  sort(gem, gem + N, comp);
  sort(bag, bag + K);

  int idx = 0;
  for (int i = 0; i < K; i++) {
    while (idx < N && bag[i] >= gem[idx].second) {
      pq.push(gem[idx]);
      idx++;
    }
    if (pq.empty()) continue;
    ans += pq.top().first;
    pq.pop();
  }

  cout << ans << "\n";

  return 0;
}
