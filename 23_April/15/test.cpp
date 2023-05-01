#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int n, maX, maxIdx;
int first, second, m;
int arr[500005];
int numArr[8008];

void sum_average() {
  double sum;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  sum /= n;
  cout << int(round(sum)) << "\n";
  return;
}

void center() {
  int center = (n - 1) / 2;
  cout << arr[center] << "\n";
  return;
}

void range() {
  cout << arr[n - 1] - arr[0] << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    numArr[arr[i] + 4000]++;
  }

  sort(arr, arr + n);
  sum_average();
  center();
  for (int i = 8000; i >= 0; i--) {
    if (m <= numArr[i]) {
      second = first;
      first = i - 4000;
      m = numArr[i];
    }
  }
  if (numArr[first + 4000] == numArr[second + 4000])
    cout << second << "\n";
  else
    cout << first << "\n";
  range();

  return 0;
}