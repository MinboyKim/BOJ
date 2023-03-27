#include <iostream>
#define MAX 1'999'999'999

using namespace std;

int N, M, B, Min, Max, ansTime = MAX, ansHeight;
int Arr[555][555];

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> M >> B;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> Arr[i][j];
      if (Min > Arr[i][j])
        Min = Arr[i][j];
      else if (Max < Arr[i][j])
        Max = Arr[i][j];
    }

  for (int k = Min; k <= Max; k++) {
    int del = 0, fill = 0, tmp = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
        if (k < Arr[i][j])
          del += Arr[i][j] - k;
        else if (k > Arr[i][j])
          fill += k - Arr[i][j];
      }

    if (del + B >= fill) {
      tmp += del * 2 + fill;
      if (ansTime >= tmp) {
        ansTime = tmp;
        if (ansHeight < k) ansHeight = k;
      }
    }
  }
  cout << ansTime << " " << ansHeight << "\n";

  return 0;
}