#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, K;
vector<pii> Edges[101'010];
int depth[101'010];
int parent[101'010][22];
int Visit[101'010];
int Min[101'010][22];
int Max[101'010][22];

void dfs(int node, int d) {
  depth[node] = d;
  Visit[node] = 1;
  for (auto &i : Edges[node]) {
    if (!Visit[i.first]) {
      parent[i.first][0] = node;
      Min[i.first][0] = i.second;
      Max[i.first][0] = i.second;
      dfs(i.first, d + 1);
    }
  }
}

void setParent() {
  dfs(1, 0);
  for (int i = 1; i < 22; i++) {
    for (int j = 1; j <= N; j++) {
      parent[j][i] = parent[parent[j][i - 1]][i - 1];
      Min[j][i] = min(Min[parent[j][i - 1]][i - 1], Min[j][i - 1]);
      Max[j][i] = max(Max[parent[j][i - 1]][i - 1], Max[j][i - 1]);
    }
  }
}

void LCA(int a, int b) {
  int minAns = 9'999'999, maxAns = 0;
  if (depth[a] > depth[b]) swap(a, b);

  for (int i = 21; i >= 0; i--)
    if (depth[b] - depth[a] >= (1 << i)) {
      minAns = min(minAns, Min[b][i]);
      maxAns = max(maxAns, Max[b][i]);
      b = parent[b][i];
    }

  if (a == b) {
    cout << minAns << " " << maxAns << "\n";
    return;
  }
  for (int i = 21; i >= 0; i--) {
    if (parent[a][i] != parent[b][i]) {
      minAns = min(minAns, Min[a][i]);
      minAns = min(minAns, Min[b][i]);
      maxAns = max(maxAns, Max[a][i]);
      maxAns = max(maxAns, Max[b][i]);

      a = parent[a][i];
      b = parent[b][i];
    }
  }

  minAns = min(minAns, Min[a][0]);
  minAns = min(minAns, Min[b][0]);
  maxAns = max(maxAns, Max[a][0]);
  maxAns = max(maxAns, Max[b][0]);

  cout << minAns << " " << maxAns << "\n";
  return;
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  int A, B, C, D, E;
  for (int i = 0; i < N - 1; i++) {
    cin >> A >> B >> C;
    Edges[A].push_back({B, C});
    Edges[B].push_back({A, C});
  }

  for (int i = 0; i < 101'010; i++) {
    for (int j = 0; j < 22; j++) Min[i][j] = 9'999'999;
  }

  setParent();

  cin >> K;
  while (K--) {
    cin >> D >> E;
    LCA(D, E);
  }

  return 0;
}