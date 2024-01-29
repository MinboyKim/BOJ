#include <cmath>
#include <iostream>

using namespace std;

double A, B, M;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> B;

  M = (B - A) / 400;
  cout << 1 / (1 + pow(10, M)) << "\n";

  return 0;
}