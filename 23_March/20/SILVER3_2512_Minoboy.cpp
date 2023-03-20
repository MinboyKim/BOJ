#include <algorithm>
#include <iostream>

using namespace std;

int N, M, total;
int Arr[10101];

int binary_search() {
  int l = 0;
  int r = Arr[N - 1];
  while (l <= r) {
    int sum = 0;
    int mid = (l + r) / 2;
    for (int i = 0; i < N; i++) {
      if (Arr[i] < mid)
        sum += Arr[i];
      else
        sum += mid;
    }
    if (sum <= M)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return r;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
    total += Arr[i];
  }
  sort(Arr, Arr + N);
  cin >> M;
  cout << binary_search() << "\n";

  return 0;
}