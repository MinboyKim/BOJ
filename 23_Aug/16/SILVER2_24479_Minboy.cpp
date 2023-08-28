#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, R, idx;
vector<int> Edges[101'010];
int Visit[101'010];

void dfs(int node) {
  idx++;
  Visit[node] = idx;
  sort(Edges[node].begin(), Edges[node].end());
  for (auto &i : Edges[node])
    if (!Visit[i]) dfs(i);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M >> R;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
  }

  dfs(R);

  for (int i = 1; i <= N; i++) cout << Visit[i] << "\n";

  return 0;
}