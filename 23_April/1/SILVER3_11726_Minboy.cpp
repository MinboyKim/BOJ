#include <iostream>

using namespace std;

int n;
int Arr[2020];

int main(void) {
  cin.tie(NULL)->ios::sync_with_stdio(false);

  cin >> n;

  Arr[1] = 1;
  Arr[2] = 2;
  for (int i = 3; i <= n; i++) Arr[i] = (Arr[i - 2] + Arr[i - 1]) % 10'007;
  cout << Arr[n] << "\n";

  return 0;
}