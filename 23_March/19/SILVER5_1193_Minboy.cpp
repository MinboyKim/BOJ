#include <iostream>

using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  int i = 1;
  while (N > i) {
    N -= i;
    i++;
  }

  if (i % 2 == 0)
    cout << N << "/" << i + 1 - N << "\n";
  else
    cout << i + 1 - N << "/" << N << "\n";

  return 0;
}