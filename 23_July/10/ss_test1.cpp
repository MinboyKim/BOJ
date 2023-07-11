#include <bits/stdc++.h>

using namespace std;

int t, n, m, x, y, cost;
vector<int> node[404];
int grouped[404];
int discover[404];
stack<int> stk;
int edgeCost[404][404];
int sequence[404];
int sq;
int minCost;

void addScc(int x);

int makeScc(int cur) {
  discover[cur] = 1;
  sequence[cur] = sq++;
  int parent = sequence[cur];

  stk.push(cur);

  for (int i = 0; i < node[cur].size(); i++) {
    int nextNode = node[cur][i];
    if (grouped[nextNode]) continue;
    if (discover[nextNode]) {  // 방문할 노드가 scc를 이루지 않았지만 이미 방문했을때
      parent = min(parent, sequence[nextNode]);
      continue;
    }
    parent = min(parent, makeScc(nextNode));
  }

  if (parent == sequence[cur]) {
    addScc(cur);
  }

  return parent;
}

void addScc(int cur) {
  vector<int> newScc;
  int tmp, tmp2, result = 0;
  while (true) {
    tmp = stk.top();
    newScc.push_back(tmp);
    grouped[tmp] = 1;
    stk.pop();
    if (tmp == cur) {
      break;
    }
  }

  if (newScc.size() == 1) {
    cur = newScc[0];
    if (edgeCost[cur][cur] == 0)
      return;
    else
      result = edgeCost[cur][cur];
  } else {
    for (int i = 0; i < newScc.size(); i++) {
      if (i == newScc.size() - 1) {
        result += edgeCost[newScc[0]][newScc[i]];
      } else
        result += edgeCost[newScc[i + 1]][newScc[i]];
    }
  }

  minCost = min(minCost, result);

  return;
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  cin >> t;
  for (int i = 1; i <= t; i++) {
    for (int i = 0; i < 404; i++) {
      while (!node[i].empty()) node[i].pop_back();
      grouped[i] = 0;
      discover[i] = 0;
      edgeCost[i][i] = 0;
      sequence[i] = 0;
    }
    minCost = 999999999;
    sq = 1;
    cin >> n >> m;
    while (m--) {
      cin >> x >> y >> cost;
      node[x].push_back(y);
      edgeCost[x][y] = cost;
    }
    for (int i = 1; i <= n; i++) {
      if (!discover[i]) makeScc(i);
    }
    if (minCost == 999999999)
      cout << "#" << i << " " << -1 << '\n';
    else
      cout << "#" << i << " " << minCost << '\n';
  }
}