#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Edges[50'505];
int depth[50'505];
int Visit[50'505];
int parent[50'505];

void dfs(int node, int d) {
  depth[node] = d;
  Visit[node] = 1;
  for (auto &i : Edges[node]) {
    if (!Visit[i]) {
      parent[i] = node;
      dfs(i, d + 1);
    }
  }
}

int LCA(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  while (depth[a] != depth[b]) b = parent[b];
  while (a != b) {
    a = parent[a];
    b = parent[b];
  }
  return a;
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
  }

  dfs(1, 0);

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << LCA(a, b) << "\n";
  }

  return 0;
}