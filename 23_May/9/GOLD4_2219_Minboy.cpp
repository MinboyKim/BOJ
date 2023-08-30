#include <iostream>

using namespace std;

int N, M, ans;
int dist[222][222];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  int A, B, C;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (i != j) dist[i][j] = 999'999'999;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    dist[A][B] = C;
    dist[B][A] = C;
  }

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int Min = 999'999'999;
  for (int i = 1; i <= N; i++) {
    int temp = 0;
    for (int j = 1; j <= N; j++) {
      temp += dist[i][j];
    }
    if (temp < Min) {
      ans = i;
      Min = temp;
    }
  }

  cout << ans << "\n";

  return 0;
}