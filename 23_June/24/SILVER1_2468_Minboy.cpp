#include <iostream>

using namespace std;

int N, MH, ans;
int Arr[111][111];
int Visit[111][111];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> Arr[i][j];
      MH = max(MH, Arr[i][j]);
    }

  for (int i = 0; i <= MH; i++) {
  }

  return 0;
}