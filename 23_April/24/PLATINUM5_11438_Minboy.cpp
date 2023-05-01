#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Edges[101'010];
int depth[101'010];
int parent[101'010][22];
int Visit[101'010];

void dfs(int node, int d) {
  depth[node] = d;
  Visit[node] = 1;
  for (auto &i : Edges[node]) {
    if (!Visit[i]) {
      parent[i][0] = node;
      dfs(i, d + 1);
    }
  }
}

void setParent() {
  dfs(1, 0);
  for (int i = 1; i < 22; i++)
    for (int j = 1; j <= N; j++) {
      parent[j][i] = parent[parent[j][i - 1]][i - 1];
    }
}

int LCA(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);

  for (int i = 21; i >= 0; i--)
    if (depth[b] - depth[a] >= (1 << i)) b = parent[b][i];

  if (a == b) return a;
  for (int i = 21; i >= 0; i--)
    if (parent[a][i] != parent[b][i]) {
      a = parent[a][i];
      b = parent[b][i];
    }

  return parent[a][0];
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

  setParent();

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << LCA(a, b) << "\n";
  }

  return 0;
}