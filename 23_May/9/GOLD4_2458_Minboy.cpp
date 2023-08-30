#include <iostream>

using namespace std;

int N, M, ans;
int dist[555][555];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  int a, b;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (i != j) dist[i][j] = 999'999'999;

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    dist[a][b] = 1;
  }

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++)
      if (dist[i][j] != 999'999'999 || dist[j][i] != 999'999'999) cnt++;
    if (cnt == N) ans++;
  }

  cout << ans << "\n";

  return 0;
}