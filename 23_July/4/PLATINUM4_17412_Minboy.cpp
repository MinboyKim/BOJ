#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, P;
vector<int> Edges[444];
int capacity[444][444];
int flow[444][444];
int parent[444];

int maxFlow(int src, int sink) {
  int result = 0;
  while (true) {
    for (int i = 1; i <= N; i++) parent[i] = -1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto &next : Edges[cur]) {
        if (parent[next] == -1 && capacity[cur][next] > flow[cur][next]) {
          q.push(next);
          parent[next] = cur;
          if (next == sink) break;
        }
      }
    }

    if (parent[sink] == -1) break;
    int minCap = 1'999'999'999;
    for (int cur = sink; cur != src; cur = parent[cur]) {
      minCap = min(minCap, capacity[parent[cur]][cur] - flow[parent[cur]][cur]);
    }
    for (int cur = sink; cur != src; cur = parent[cur]) {
      flow[parent[cur]][cur] += minCap;
      flow[cur][parent[cur]] -= minCap;
    }
    result++;
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> P;
  int a, b;
  for (int i = 0; i < P; i++) {
    cin >> a >> b;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
    capacity[a][b] = 1;
  }

  cout << maxFlow(1, 2) << "\n";

  return 0;
}