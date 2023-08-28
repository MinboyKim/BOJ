#include <iostream>

using namespace std;

int N, M;
int Arr[101'010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> Arr[i];
    Arr[i] += Arr[i - 1];
  }
  int a, b;
  while (M--) {
    cin >> a >> b;
    cout << Arr[b] - Arr[a - 1] << "\n";
  }

  return 0;
}