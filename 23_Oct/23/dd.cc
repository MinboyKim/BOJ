#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int main() {
  int n, a, b, tmp;
  arr[1] = 1;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
  }
  for (int i = 1; i <= 3; i++) {
    if (arr[i] == 1) {
      cout << i;
      break;
    }
  }
}