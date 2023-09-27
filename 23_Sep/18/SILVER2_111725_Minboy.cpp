#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Edges[101'010];
int parent[101'010];

void dfs(int node) {
  for (auto &i : Edges[node]) {
    if (!parent[i]) {
      parent[i] = node;
      dfs(i);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
  }

  dfs(1);
  for (int i = 2; i <= N; i++) cout << parent[i] << "\n";

  return 0;
}