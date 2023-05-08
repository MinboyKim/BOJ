#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void dfs(int d, int idx) {
  if (d == M) {
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
    return;
  }
  for (int i = idx; i <= N; i++) {
    ans.push_back(i);
    dfs(d + 1, i);
    ans.pop_back();
  }
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> M;

  dfs(0, 1);

  return 0;
}