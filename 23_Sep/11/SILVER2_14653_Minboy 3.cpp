#include <iostream>

using namespace std;

int N, K, Q;
int num[10'101];
char sender[10'101];
int ans[30];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> K >> Q;

  for (int i = 1; i <= K; i++) cin >> num[i] >> sender[i];

  if (!num[Q]) {
    cout << -1 << "\n";
    return 0;
  }

  for (int i = 1; i <= K; i++)
    if (num[i] >= num[Q]) ans[sender[i] - 'A'] = 1;

  ans[0] = 1;

  for (int i = 0; i < N; i++)
    if (!ans[i]) cout << char('A' + i) << " ";

  return 0;
}