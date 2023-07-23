#include <iostream>

using namespace std;

int N, cnt;
int Arr[10101];

void recursion(int start, int end) {
  if (start >= end) return;
  if (start == end - 1) {
    cout << Arr[start] << "\n";
    return;
  }

  int idx = start + 1;
  while (idx < end) {
    if (Arr[start] < Arr[idx]) break;
    idx++;
  }

  recursion(start + 1, idx);
  recursion(idx, end);
  cout << Arr[start] << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  while (cin >> N) Arr[cnt++] = N;

  recursion(0, cnt);

  return 0;
}