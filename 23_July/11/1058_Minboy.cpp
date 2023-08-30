#include <iostream>
#include <string>

using namespace std;

int N, ans;
int dist[55][55];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  string s;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j) dist[i][j] = 999'999'999;
    }
  }

  for (int i = 1; i <= N; i++) {
    cin >> s;
    for (int j = 1; j <= s.length(); j++) {
      if (s[j - 1] == 'Y') dist[i][j] = 1;
    }
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      if (dist[i][j] <= 2) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}