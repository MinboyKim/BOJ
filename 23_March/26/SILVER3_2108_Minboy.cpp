#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int N, first, second, m;
double sum;
int Arr[505'505];
int cnt[8080];

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
    cnt[Arr[i] + 4000]++;
    sum += Arr[i];
  }

  cout << int(round(sum / N)) << "\n";
  sort(Arr, Arr + N);
  cout << Arr[(N - 1) / 2] << "\n";

  for (int i = 8000; i >= 0; i--) {
    if (m <= cnt[i]) {
      second = first;
      first = i - 4000;
      m = cnt[i];
    }
  }
  if (cnt[first + 4000] == cnt[second + 4000])
    cout << second << "\n";
  else
    cout << first << "\n";

  cout << Arr[N - 1] - Arr[0] << "\n";

  return 0;
}