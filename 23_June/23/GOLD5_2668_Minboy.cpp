#include <iostream>
#include <vector>

using namespace std;

int Arr[111];
int N;
int Visit[111];
vector<int> ans;

void dfs(int cur, int start) {
  if (Visit[cur]) {
    if (cur == start) ans.push_back(cur);
    return;
  }
  Visit[cur] = 1;
  dfs(Arr[cur], start);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> Arr[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) Visit[j] = 0;
    dfs(i, i);
  }

  cout << ans.size() << "\n";
  for (auto &i : ans) cout << i << "\n";

  return 0;
}