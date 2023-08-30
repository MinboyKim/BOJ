#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, num;
vector<int> ans;
vector<int> Edges[10'101];
int Visit[10'101];

int dfs(int node, int flag) {
  int ret = 1;
  if (flag)
    for (int i = 1; i <= N; i++) Visit[i] = 0;
  Visit[node] = 1;
  for (auto &i : Edges[node])
    if (!Visit[i]) ret += dfs(i, 0);
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  int a, b;
  for (int i = 1; i <= M; i++) {
    cin >> a >> b;
    Edges[b].push_back(a);
  }

  for (int i = 1; i <= N; i++) {
    int temp = dfs(i, 1);
    if (num < temp) {
      num = temp;
      ans.clear();
      ans.push_back(i);
    } else if (num == temp)
      ans.push_back(i);
  }

  for (auto &i : ans) cout << i << " ";

  return 0;
}