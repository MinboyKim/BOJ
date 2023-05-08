#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N;
string Arr[55];

int cmpSum(string a, string b) {
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < a.length(); i++)
    if (a[i] >= '0' && a[i] <= '9') sum1 += a[i] - '0';
  for (int i = 0; i < b.length(); i++)
    if (b[i] >= '0' && b[i] <= '9') sum2 += b[i] - '0';
  if (sum1 > sum2)
    return 1;
  else if (sum1 == sum2)
    return 0;
  return -1;
}

bool compare(string a, string b) {
  if (a.length() > b.length())
    return false;
  else if (a.length() == b.length()) {
    int temp = cmpSum(a, b);
    if (temp == 1)
      return false;
    else if (temp == 0)
      if (a > b) return false;
  }
  return true;
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  sort(Arr, Arr + N, compare);
  for (int i = 0; i < N; i++) cout << Arr[i] << "\n";

  return 0;
}