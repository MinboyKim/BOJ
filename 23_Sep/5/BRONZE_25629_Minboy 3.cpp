#include <iostream>

using namespace std;

int N, odd, even;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (a % 2 == 0)
      even++;
    else
      odd++;
  }
  if (N == 1 && odd)
    cout << 1 << "\n";
  else if ((N % 2 == 1 && even != (N / 2)) || (N % 2 == 0 && even != (N / 2)))
    cout << 0 << "\n";
  else
    cout << 1 << "\n";

  return 0;
}