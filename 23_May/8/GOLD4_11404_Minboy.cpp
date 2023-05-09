#include <iostream>

using namespace std;

int n, m;
int dist[111][111];

void floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  int a, b, c;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) dist[i][j] = 999'999'999;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (c < dist[a][b]) dist[a][b] = c;
  }

  floyd();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      dist[i][j] == 999'999'999 ? cout << 0 << " " : cout << dist[i][j] << " ";
    cout << "\n";
  }

  return 0;
}