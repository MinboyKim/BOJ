#include <iostream>

using namespace std;

int N, M, ansT = 1e9, ansA, ansB;
int Arr[111][111];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      Arr[i][j] = 1e9;
    }
  }

  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    Arr[a][b] = 1;
    Arr[b][a] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        Arr[i][j] = min(Arr[i][j], Arr[i][k] + Arr[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      int t = 0;
      for (int k = 1; k <= N; k++) {
        t += min(Arr[k][i] * 2, Arr[k][j] * 2);
      }
      if (t < ansT) {
        ansT = t;
        ansA = i;
        ansB = j;
      }
    }
  }

  cout << ansA << " " << ansB << " " << ansT << "\n";

  return 0;
}