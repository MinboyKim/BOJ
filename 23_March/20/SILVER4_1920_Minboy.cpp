#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int Arr[101010];

int binary_search(int num) {
  int l = 0;
  int r = N - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (Arr[mid] == num)
      return 1;
    else if (Arr[mid] > num)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  sort(Arr, Arr + N);

  cin >> M;
  int a;
  for (int i = 0; i < M; i++) {
    cin >> a;
    cout << binary_search(a) << "\n";
  }

  return 0;
}