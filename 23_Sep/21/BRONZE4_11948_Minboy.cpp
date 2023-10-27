#include <algorithm>
#include <iostream>

using namespace std;

int Arr1[4], Arr2[2], ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  for (int i = 0; i < 4; i++) cin >> Arr1[i];
  for (int i = 0; i < 2; i++) cin >> Arr2[i];
  sort(Arr1, Arr1 + 4, greater<int>());
  sort(Arr2, Arr2 + 2, greater<int>());
  for (int i = 0; i < 3; i++) ans += Arr1[i];
  ans += Arr2[0];
  cout << ans << "\n";

  return 0;
}