#include <iostream>

using namespace std;

int n;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  int a;
  while (n--) {
    cin >> a;
    if (a == 1 || a == 2)
      cout << "Pairs for " << a << ":\n";
    else {
      cout << "Pairs for " << a << ": ";
      for (int i = 1; i < a; i++) {
        int b = a - i;
        cout << i << " " << b;
        if ((a % 2 == 0 && i == b - 2) || (a % 2 == 1 && i == b - 1)) {
          cout << "\n";
          break;
        }
        cout << ", ";
      }
    }
  }

  return 0;
}