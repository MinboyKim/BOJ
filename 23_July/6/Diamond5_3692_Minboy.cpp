#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, N;
double D;
int capacity[250][250];
int flow[250][250];
int parent[250];
vector<int> Edges[250];

void init() {
  for (int i = 0; i < 222; i++) {
    Edges[i].clear();
    for (int j = 0; j < 222; j++) {
      capacity[i][j] = 0;
      flow[i][j] = 0;
    }
  }
}

int maxFlow(int src, int sink) {
  int result = 0;
  while (true) {
    for (int i = 0; i < 222; i++) parent[i] = -1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto &next : Edges[cur]) {
        if (parent[next] == -1 && capacity[cur][next] > flow[cur][next]) {
          parent[next] = cur;
          q.push(next);
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
    result += minCap;
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> N >> D;
    init();
    int xi[250], yi[250], ni, mi;
    int src = 220, sink = 221, peng = 0;

    for (int i = 0; i < N; i++) {
      cin >> xi[i] >> yi[i] >> ni >> mi;
      for (int j = 0; j < i; j++) {
        if ((xi[i] - xi[j]) * (xi[i] - xi[j]) +
                (yi[i] - yi[j]) * (yi[i] - yi[j]) <=
            D * D) {
          Edges[i].push_back(j + N);
          Edges[j + N].push_back(i);
          Edges[j].push_back(i + N);
          Edges[i + N].push_back(j);
          capacity[i + N][j] = 1'999'999'999;
          capacity[j + N][i] = 1'999'999'999;
        }
      }

      Edges[i].push_back(i + N);
      Edges[i + N].push_back(i);
      capacity[i][i + N] = mi;
      if (ni > 0) {
        peng += ni;
        Edges[src].push_back(i);
        Edges[i].push_back(src);
        capacity[src][i] = ni;
      }
    }
    int flag = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 222; j++)
        for (int k = 0; k < 222; k++) flow[j][k] = 0;

      Edges[i].push_back(sink);
      Edges[sink].push_back(i);
      capacity[i][sink] = 1'999'999'999;
      if (maxFlow(src, sink) == peng) {
        cout << i << " ";
        flag = 1;
      }
      Edges[i].pop_back();
      Edges[sink].pop_back();
      capacity[i][sink] = 0;
    }

    if (!flag) {
      cout << -1;
    }
    cout << "\n";
  }

  return 0;
}