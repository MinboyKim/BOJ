#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, N, M;
vector<int> Edges[222];
int capacity[222][222];
int flow[222][222];
int parent[222];

void init() {
  for (int i = 1; i <= N; i++) {
    Edges[i].clear();
    for (int j = 1; j <= N; j++) {
      capacity[i][j] = 0;
      flow[i][j] = 0;
    }
  }
}

int maxFlow(int src, int sink) {
  int result = 0;

  while (true) {
    for (int i = 1; i <= N; i++) parent[i] = -1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto &i : Edges[cur]) {
        if (parent[i] == -1 && capacity[cur][i] > flow[cur][i]) {
          q.push(i);
          parent[i] = cur;
          if (i == sink) break;
        }
      }
    }

    if (parent[sink] == -1) break;
    int minCap = 1'999'999'999;
    int cur = sink;
    while (cur != src) {
      minCap = min(minCap, capacity[parent[cur]][cur] - flow[parent[cur]][cur]);
      cur = parent[cur];
    }
    cur = sink;
    while (cur != src) {
      flow[parent[cur]][cur] += minCap;
      flow[cur][parent[cur]] -= minCap;
      cur = parent[cur];
    }
    result += minCap;
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> N >> M;
    init();
    int a, b;
    for (int i = 0; i < M; i++) {
      cin >> a >> b;
      Edges[a].push_back(b);
      Edges[b].push_back(a);
      if (a == 1 || b == N)
        capacity[a][b] = 1;
      else
        capacity[a][b] = 1'999'999'999;
    }

    cout << maxFlow(1, N) << "\n";
  }

  return 0;
}