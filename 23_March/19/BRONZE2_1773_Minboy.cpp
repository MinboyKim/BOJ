#include <iostream>

using namespace std;

int N, C, ans;
int Arr[111];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  for (int i = 1; i <= C; i++) {
    for (int j = 0; j < N; j++) {
      if (i % Arr[j] == 0) {
        ans++;
        break;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}