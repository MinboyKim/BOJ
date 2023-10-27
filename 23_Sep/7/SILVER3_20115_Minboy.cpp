#include <algorithm>
#include <iostream>

using namespace std;

int N;
double Arr[101'010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  sort(Arr, Arr + N);
  for (int i = 0; i < N - 1; i++) Arr[N - 1] += Arr[i] / 2;

  cout << Arr[N - 1] << "\n";

  return 0;
}