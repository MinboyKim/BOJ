#include <iostream>

using namespace std;

double A, B, T;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> A >> B;
    cout << (long long)(A / B * A / B) << "\n";
  }

  return 0;
}