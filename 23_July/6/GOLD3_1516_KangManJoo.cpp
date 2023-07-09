#include <bits/stdc++.h>

using namespace std;

int n, t, cur;
vector<int> node[505];
int cost[505];
int preCost[505];
int degree[505];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
    int pre;
    while (true) {
      cin >> pre;
      if (pre == -1) break;
      node[pre].push_back(i);
      degree[i]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!degree[i]) q.push(i);
  }

  while (!q.empty()) {
    cur = q.front();
    q.pop();
    cost[cur] += preCost[cur];
    for (int i = 0; i < node[cur].size(); i++) {
      int next = node[cur][i];
      if (!preCost[next])
        preCost[next] = cost[cur];
      else
        preCost[next] = max(preCost[next], cost[cur]);
      if (--degree[next] == 0) q.push(next);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << cost[i] << "\n";
  }
}