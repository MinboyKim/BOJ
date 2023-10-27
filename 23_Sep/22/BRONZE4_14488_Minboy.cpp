#include <iostream>

using namespace std;

int A, B, C;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> B >> C;

  A += B;
  C *= 2;
  cout << (A >= C ? A - C : A) << "\n";

  return 0;
}