#include <iostream>

using namespace std;

int Arr[10];
int sum;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 9; i++) {
    cin >> Arr[i];
    sum += Arr[i];
  }
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      int tmp = sum;
      tmp -= Arr[i] + Arr[j];
      if (tmp == 100) {
        for (int k = 0; k < 9; k++)
          if (k != i && k != j) cout << Arr[k] << "\n";
        return 0;
      }
    }
  }

  return 0;
}