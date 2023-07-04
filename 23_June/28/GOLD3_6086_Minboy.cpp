#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int capacity[130][130];
int flow[130][130];
int parent[130];
vector<int> Edges[130];

int maxFlow(int start, int end) {
  int result = 0;

  while (true) {
    for (int i = 60; i < 130; i++) parent[i] = -1;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto &i : Edges[cur]) {
        if (parent[i] == -1 && capacity[cur][i] > flow[cur][i]) {
          q.push(i);
          parent[i] = cur;
          if (i == end) break;
        }
      }
    }

    if (parent[end] == -1) break;
    int minCap = 1'999'999'999;
    int cur = end;
    while (cur != start) {
      minCap = min(minCap, capacity[parent[cur]][cur] - flow[parent[cur]][cur]);
      cur = parent[cur];
    }

    cur = end;
    while (cur != start) {
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

  cin >> N;
  char a, b;
  int c;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
    capacity[a][b] += c;
    capacity[b][a] += c;
  }

  cout << maxFlow('A', 'Z') << "\n";

  return 0;
}