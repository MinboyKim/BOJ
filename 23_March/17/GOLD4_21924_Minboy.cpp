#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<long long, long long> pii;

struct compare {
  bool operator()(pii a, pii b) { return a.second > b.second; }
};

long long N, M, all, ans;
vector<pii> Edges[100'100];
priority_queue<pii, vector<pii>, compare> pq;
int Visit[100'100];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  int A, B, C;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    all += C;
    Edges[A].push_back({B, C});
    Edges[B].push_back({A, C});
  }

  Visit[A] = 1;
  for (auto &i : Edges[A]) pq.push(i);

  while (!pq.empty()) {
    pii temp = pq.top();
    pq.pop();
    if (!Visit[temp.first]) {
      ans += temp.second;
      Visit[temp.first] = 1;
    }
    for (auto &i : Edges[temp.first])
      if (!Visit[i.first]) pq.push(i);
  }

  for (int i = 1; i <= N; i++) {
    if (!Visit[i]) {
      cout << -1 << "\n";
      return 0;
    }
  }

  ans = all - ans;
  cout << ans << "\n";

  return 0;
}