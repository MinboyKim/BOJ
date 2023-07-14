#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m, r;
int item[101];
int dist[101][101];

int main() {
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> item[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= n; k++) {
      if (i == k) {
        dist[i][k] = 0;
      } else {
        dist[i][k] = INF;
      }
    }
  }

  int Pnode, Nnode, cost;
  while (r--) {
    cin >> Pnode >> Nnode >> cost;
    dist[Pnode][Nnode] = cost;
    dist[Nnode][Pnode] = cost;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int maxSum = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] <= m) {
        sum += item[j];
      }
    }
    maxSum = max(maxSum, sum);
  }
  cout << maxSum;
}