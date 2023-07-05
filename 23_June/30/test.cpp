#include <iostream>

using namespace std;

int A[55], B[55];
int K;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> K;
  A[1] = 1;
  A[2] = 0;
  B[1] = 0;
  B[2] = 1;
  for (int i = 3; i <= K + 1; i++) {
    A[i] = B[i - 1];
    B[i] = A[i - 1] + B[i - 1];
  }

  cout << A[K + 1] << " " << B[K + 1];

  return 0;
}