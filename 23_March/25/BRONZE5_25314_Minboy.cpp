#include <iostream>

using namespace std;

int N, cnt;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  while (N > 0) {
    cnt++;
    N -= 4;
  }
  for (int i = 0; i < cnt; i++) cout << "long ";

  cout << "int\n";

  return 0;
}