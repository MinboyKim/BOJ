#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int t, n, m, x, y, cost;
vector<pii> node[404];
int visited[404];
int finished[404];
int toMoveCost[404];
int minCost;

void dfs(int cur, int curCost) {
  visited[cur] = 1;
  toMoveCost[cur] = curCost;
  for (int i = 0; i < node[cur].size(); i++) {
    pii next = node[cur][i];
    int Nnode = next.first;
    if (finished[Nnode]) continue;

    int edgeCostSum = curCost + next.second;

    if (visited[Nnode] && !finished[Nnode]) {
      int resultCost = edgeCostSum - toMoveCost[Nnode];
      minCost = min(minCost, resultCost);
    } else {
      dfs(Nnode, edgeCostSum);
    }
  }

  finished[cur] = 1;
}

void init() {
  for (int i = 0; i < 404; i++) {
    while (!node[i].empty()) node[i].pop_back();
    finished[i] = 0;
    visited[i] = 0;
    toMoveCost[i] = 0;

    minCost = 1999999999;
  }
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  cin >> t;

  for (int i = 1; i <= t; i++) {
    init();

    cin >> n >> m;
    while (m--) {
      cin >> x >> y >> cost;
      node[x].push_back({y, cost});
    }

    for (int i = 1; i <= n; i++) {
      if (!finished[i]) dfs(i, 0);
    }
    if (minCost == 1999999999)
      cout << "#" << i << " " << -1 << endl;
    else
      cout << "#" << i << " " << minCost << endl;
  }
}