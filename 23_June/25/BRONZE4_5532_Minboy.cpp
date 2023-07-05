#include <iostream>

using namespace std;

int L, A, B, C, D;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> L >> A >> B >> C >> D;

  int r1, r2;
  if (A % C == 0)
    r1 = A / C;
  else
    r1 = A / C + 1;
  if (B % D == 0)
    r2 = B / D;
  else
    r2 = B / D + 1;

  cout << L - max(r1, r2) << "\n";

  return 0;
}