#include <iostream>

using namespace std;

int N, M, ansSum = 999'999'999, ansN;
int dist[111][111];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      dist[i][j] = 999'999;
    }
  }

  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int temp = 0;
    for (int j = 1; j <= N; j++) {
      temp += dist[i][j];
    }
    if (ansSum > temp) {
      ansN = i;
      ansSum = temp;
    }
  }

  cout << ansN << "\n";

  return 0;
}