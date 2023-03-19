#include <iostream>

using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < N - i; j++) cout << " ";
    for (int k = 0; k < 2 * i - 1; k++) cout << "*";
    cout << "\n";
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) cout << " ";
    for (int k = 0; k < 2 * N - (2 * i + 1); k++) cout << "*";
    cout << "\n";
  }

  return 0;
}

*****************************************