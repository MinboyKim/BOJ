#include <iostream>
#include <string>

using namespace std;

string N, M;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  cout << (N == M ? 1 : 0) << "\n";

  return 0;
}