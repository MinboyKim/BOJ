#include <algorithm>
#include <iostream>

using namespace std;

int K, N;
int Arr[55];

bool compare(int a, int b) { return a < b; }

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> K;

  for (int i = 1; i <= K; i++) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Arr[i];

    sort(Arr, Arr + N, compare);

    int gap = 0;
    for (int i = 0; i < N - 1; i++) gap = max(gap, Arr[i + 1] - Arr[i]);

    cout << "Class " << i << "\n";
    cout << "Max " << Arr[N - 1] << ", Min " << Arr[0] << ", Largest gap "
         << gap << "\n";
  }

  return 0;
}