#include <iostream>

using namespace std;

int N, M;
int Arr[11];
int ans[11];

void dfs(int d) {
  if (d == M) {
    for (int i = 0; i < M; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  for (int i = 1; i <= N; i++) {
    ans[d] = Arr[i];
    dfs(d + 1);
  }
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= 10; i++) Arr[i] = i;

  dfs(0);

  return 0;
}