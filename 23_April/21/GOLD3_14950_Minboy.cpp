#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M, t, ans, cost;
vector<pii> Edges[10'101];
int Visit[10'101];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> M >> t;

  int A, B, C;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    Edges[A].push_back({C, B});
    Edges[B].push_back({C, A});
  }

  Visit[1] = 1;
  for (auto &i : Edges[1]) pq.push(i);

  while (!pq.empty()) {
    pii temp = pq.top();
    pq.pop();
    if (Visit[temp.second]) continue;
    Visit[temp.second] = 1;
    ans += temp.first;
    ans += cost;
    cost += t;
    for (auto &i : Edges[temp.second])
      if (!Visit[i.second]) pq.push(i);
  }

  cout << ans << "\n";

  return 0;
}