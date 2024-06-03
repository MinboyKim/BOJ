#include <cmath>
#include <iostream>

using namespace std;

int T, ans;
int Arr[5];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;

  for (int i = 0; i < T; i++)
    cin >> Arr[i];

  if (Arr[0] > Arr[2])
    ans += 508 * abs(Arr[0] - Arr[2]);
  else
    ans += 108 * abs(Arr[0] - Arr[2]);

  if (Arr[1] > Arr[3])
    ans += 212 * abs(Arr[1] - Arr[3]);
  else
    ans += 305 * abs(Arr[1] - Arr[3]);

  if (Arr[4])
    ans += Arr[4] * 707;

  cout << ans * 4763 << "\n";

  return 0;
}
