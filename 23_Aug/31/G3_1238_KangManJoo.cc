#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int visited[1001];
int dist[1001];
int moveCost[1001];
vector<pii> node[1001];
int backCost[1001];

struct cmp {
  bool operator()(pii a, pii b) { 
    if(a.first>b.first)
        return a.second > b.second; 
    else
        return a.second >b.second;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

int n, m, x;

void addEdge(int cur, int preCost) {
  for (int i = 0; i < node[cur].size(); i++) {
    int cost = node[cur][i].second;
    int nextNode = node[cur][i].first;
    pq.push({nextNode, cost + preCost});
  }
}

void dijkstra(int cur) {
  addEdge(cur, 0);
  int preNode = cur;
  visited[cur] = 1;

  while (!pq.empty()) {
    pii next = pq.top();
    pq.pop();
    int nextNode = next.first;
    int cost = next.second;
    if (visited[nextNode]) continue;
    visited[nextNode] = 1;
    dist[nextNode] = cost;
    addEdge(nextNode, cost);
  }
}

void init() {
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
    dist[i] = INT_MAX;
  }
}

int main() {
  cin >> n >> m >> x;

  int Pnode, Nnode, cost;
  while (m--) {
    cin >> Pnode >> Nnode >> cost;
    node[Pnode].push_back({Nnode, cost});
  }

  dijkstra(x);
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    backCost[i] = dist[i];
  }

  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    init();
    dist[i] = 0;
    dijkstra(i);
    moveCost[i] = dist[x];
  }

  int maxCost = 0;
  for (int i = 1; i <= n; i++) {
    int totalCost = moveCost[i] + backCost[i];
    if (totalCost > maxCost) maxCost = totalCost;
  }

  cout << maxCost;
}