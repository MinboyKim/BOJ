#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int N, cnt;
int Arr[1111][1111];
pii a, b;

int solve(pii a, pii b) {
  int minR = min(a.first, b.first);
  int minC = min(a.second, b.second);
  int maxR = max(a.first, b.first);
  int maxC = max(a.second, b.second);
  for (int i = minC; i <= maxC; i++)
    for (int j = minR; j <= maxR; j++)
      if (Arr[j][i] == 1) cnt++;

  int dist = ((maxR - minR) * (maxR - minR)) + ((maxC - minC) * (maxC - minC));
  if (cnt >= 3 && dist >= 25)
    return 1;
  else
    return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> Arr[i][j];
      if (Arr[i][j] == 2) a = {i, j};
      if (Arr[i][j] == 5) b = {i, j};
    }

  cout << solve(a, b) << "\n";

  return 0;
}