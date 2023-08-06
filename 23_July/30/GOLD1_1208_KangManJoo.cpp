#include <bits/stdc++.h>

using namespace std;

long long n, target, cnt, front, back;
int arr[44];
vector<long long> targetSet;

// 부분수열과 부분집합은 다르다. 부분수열의 경우 {2,3,5,7} 이 있을 때 {2,5,7}등
// 원하는 원소를 뺀 모든것이 부분수열이 된다.
void dfsF(long long start, long long sum) {
  if (start >= front) return;

  sum += arr[start];

  if (sum == target) {
    cnt++;
  }
  targetSet.push_back(sum);

  dfsF(start + 1, sum - arr[start]);
  dfsF(start + 1, sum);
}

void dfsB(long long start, long long sum) {
  if (start >= back) return;

  sum += arr[start];

  if (sum == target) {
    cnt++;
  }
  int t = target - sum;
  int upperIndex =
      upper_bound(targetSet.begin(), targetSet.end(), t) - targetSet.begin();
  int lowerIndex =
      lower_bound(targetSet.begin(), targetSet.end(), t) - targetSet.begin();
  cnt+=upperIndex-lowerIndex;

  dfsB(start + 1, sum - arr[start]);
  dfsB(start + 1, sum);
}

int main() {
  cin >> n >> target;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  front = n / 2;
  back = n;
  dfsF(0, 0);
  sort(targetSet.begin(), targetSet.end());
  dfsB(front, 0);
  cout << cnt;
}