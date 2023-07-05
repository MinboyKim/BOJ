#include <bits/stdc++.h>
#define MAX 3'300'000'003
using namespace std;

typedef long long ll;
ll arr[5005];
ll ans = MAX;
int minA, minB, minC;

int main() {
  int n, i, j, left, right, first;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);


  ll twoSum, threeSum, tmp;
  for (j = 0; j < n - 2; j++) {
    first = j;
    left = j + 1;
    right = n - 1;
    while (left<right) {
      threeSum = arr[first] + arr[left] + arr[right];

      if (abs(threeSum) < abs(ans)) {
        ans = threeSum;
        minA = arr[first];
        minB = arr[left];
        minC = arr[right];
      }
      if (threeSum > 0)
        right--;
      else if (threeSum < 0)
        left++;
      else{
        break;
      }
    }
  }

  cout << minA << " " << minB << " " << minC;
}