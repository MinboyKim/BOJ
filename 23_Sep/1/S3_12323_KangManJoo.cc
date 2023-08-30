#include <bits/stdc++.h>

using namespace std;

int arr[100];

int curSize, n;

int main() {
  int t, tcNum = 1, result;
  cin >> t;
  while (t--) {
    cin >> curSize >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);

    result = n;

    if (curSize != 1) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        while (curSize <= arr[i]) {
          curSize += curSize - 1;
          cnt++;
        }
        curSize += arr[i];
        result = min(result, cnt + n - i - 1);
      }
    }

    cout << "Case #" << tcNum << ": " << result << '\n';
    tcNum++;
  }
}