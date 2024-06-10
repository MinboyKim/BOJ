#include <algorithm>
#include <iostream>

using namespace std;

int n, m, ans = 1;
int a[101'010], b[101'010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  sort(a, a + n, greater<int>());
  sort(b, b + m, greater<int>());

  int i = 0, j = 0, hole = 0;
  while (i < n && j < m) {
    if (!hole) {
      hole += a[i];
      i++;
      ans--;
    }
    while (j < m && hole) {
      hole--;
      ans += b[j];
      j++;
    }
  }

  cout << ans << "\n";

  return 0;
}