#include <iostream>
#include <string>

using namespace std;

string H;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> H;
  cout << (H == "1" ? 2 : 1) << "\n";

  return 0;
}