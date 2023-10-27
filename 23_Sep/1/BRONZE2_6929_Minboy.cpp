#include <iostream>

using namespace std;

int H;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> H;
  for (int i = 1; i <= H / 2 + 1; i++) {
    for (int j = 1; j <= i * 2 - 1; j++) cout << "*";
    for (int j = 1; j <= 2 * H - ((i * 2 - 1) * 2); j++) cout << " ";
    for (int j = 1; j <= i * 2 - 1; j++) cout << "*";
    cout << "\n";
  }
  for (int i = 1; i <= H / 2; i++) {
    for (int j = 1; j <= H - (i * 2); j++) cout << "*";
    for (int j = 1; j <= (2 * H) - (2 * (H - (i * 2))); j++) cout << " ";
    for (int j = 1; j <= H - (i * 2); j++) cout << "*";
    cout << "\n";
  }

  return 0;
}