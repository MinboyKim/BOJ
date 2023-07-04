#include <iostream>

using namespace std;

int N, student;
int Arr[111];

void male(int num) {
  int i = 1;
  int temp = num;
  while (true) {
    temp = num * i;
    if (temp > N) break;
    Arr[temp] = !Arr[temp];
    i++;
  }
}

void female(int num) {
  int i = 0;
  while (true) {
    int left = num - i;
    int right = num + i;
    if (left <= 0 || right > N) break;
    if (Arr[left] == Arr[right]) {
      Arr[left] = !Arr[left];
      Arr[right] = !Arr[right];
      if (left == right) Arr[left] = !Arr[left];
    } else
      break;
    i++;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> Arr[i];

  cin >> student;
  while (student--) {
    int a, b;
    cin >> a >> b;
    if (a == 1)
      male(b);
    else
      female(b);
  }

  for (int i = 1; i <= N; i++) {
    cout << Arr[i] << " ";
    if (i % 20 == 0) cout << '\n';
  }
  cout << "\n";

  return 0;
}