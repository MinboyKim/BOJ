#include <iostream>

using namespace std;

int a, b, M, m;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  int tmp1 = a > b ? b : a;
  int tmp2 = a > b ? a : b;
  for (int i = 1; i <= tmp1; i++)
    if (tmp2 % i == 0 && tmp1 % i == 0) M = i;
  for (int i = tmp2; i <= 100'000'000; i++) {
    if (i % tmp1 == 0 && i % tmp2 == 0) {
      m = i;
      break;
    }
  }
  cout << M << "\n" << m << "\n";

  return 0;
}