#include <iostream>

using namespace std;

int N, M;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  cout << ((M <= N) ? ((M == 1 || M == 2) ? "NEWBIE!\n" : "OLDBIE!\n")
                    : "TLE!\n");

  return 0;
}