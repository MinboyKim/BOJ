#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct compare {
  bool operator()(pii a, pii b) { return a.second > b.second; }
};

int T, n, d, c;
priority_queue<pii, vector<pii>, compare> pq;
vector<pii> Edges[10'101];
int dist[10'101];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> n >> d >> c;
    int a, b, s;

    for (int i = 1; i <= n; i++) Edges[i].clear();
    for (int i = 0; i < d; i++) {
      cin >> a >> b >> s;
      Edges[b].push_back({a, s});
    }
    for (int i = 1; i <= n; i++) dist[i] = 999'999'999;
    pq.push({c, 0});
    dist[c] = 0;
    while (!pq.empty()) {
      pii cur = pq.top();
      pq.pop();
      if (cur.second > dist[cur.first]) continue;
      for (auto &i : Edges[cur.first]) {
        if (i.second + cur.second < dist[i.first]) {
          dist[i.first] = i.second + cur.second;
          pq.push({i.first, i.second + cur.second});
        }
      }
    }
    int ansC = 0, ansS = 0;
    for (int i = 1; i <= n; i++) {
      if (dist[i] != 999'999'999) {
        ansC++;
        ansS = max(ansS, dist[i]);
      }
    }

    cout << ansC << " " << ansS << "\n";
  }

  return 0;
}