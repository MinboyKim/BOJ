#include <iostream>

using namespace std;

int N;
int Arr[10010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    Arr[a]++;
  }
  for (int i = 0; i <= 10000; i++) {
    for (int j = 0; j < Arr[i]; j++) cout << i << "\n";
  }

  return 0;
}