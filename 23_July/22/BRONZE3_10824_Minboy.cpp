#include <iostream>
#include <string>

using namespace std;

string A, B, C, D;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> B >> C >> D;

  A += B;
  C += D;
  cout << stoll(A) + stoll(C) << "\n";

  return 0;
}