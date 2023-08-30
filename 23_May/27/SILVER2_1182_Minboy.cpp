#include <iostream>

using namespace std;

int Arr[22];
int N, S, ans;

void dfs(int pos, int sum) {
  if (sum == S) ans++;
  for (int i = pos; i < N; i++) {
    sum += Arr[i];
    dfs(i + 1, sum);
    sum -= Arr[i];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  dfs(0, 0);

  cout << ((S == 0) ? ans - 1 : ans) << "\n";

  return 0;
}