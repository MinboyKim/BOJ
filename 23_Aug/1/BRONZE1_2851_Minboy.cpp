#include <cstdlib>
#include <iostream>

using namespace std;

int Arr[11];
int temp = 999'999'999, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> Arr[0];
  for (int i = 1; i < 10; i++) {
    cin >> Arr[i];
    Arr[i] += Arr[i - 1];
  }

  for (int i = 0; i < 10; i++)
    if ((temp > abs(Arr[i] - 100)) ||
        ((temp == abs(Arr[i] - 100)) && (Arr[i] > ans))) {
      temp = abs(Arr[i] - 100);
      ans = Arr[i];
    }

  cout << ans << "\n";

  return 0;
}