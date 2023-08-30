#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> Edges[1010];
int Visit[1010];

void dfs(int node) {
  Visit[node] = 1;
  for (auto &i : Edges[node])
    if (!Visit[i]) dfs(i);
}

int main(void) {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  int u, v;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    Edges[u].push_back(v);
    Edges[v].push_back(u);
  }

  for (int i = 1; i <= N; i++)
    if (!Visit[i]) {
      ans++;
      dfs(i);
    }

  cout << ans << "\n";

  return 0;
}