#include <algorithm>
#include <iostream>

using namespace std;

int N;
int Arr[1'000'100];

bool compare(int a, int b) { return a > b; }

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  sort(Arr, Arr + N, compare);

  for (int i = 0; i < N; i++) cout << Arr[i] << "\n";

  return 0;
}