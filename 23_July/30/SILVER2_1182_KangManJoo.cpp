#include <bits/stdc++.h>

using namespace std;

int n, target, cnt;
int arr[21];

//부분수열과 부분집합은 다르다. 부분수열의 경우 {2,3,5,7} 이 있을 때 {2,5,7}등 원하는 원소를 뺀 모든것이 부분수열이 된다.
void dfs(int start, int sum) {
  if(start>=n) return;

  sum += arr[start];

  if (sum == target) {
    cnt++;
  }

  dfs(start+1, sum -arr[start]);
  dfs(start+1, sum);
}

int main() {
  cin >> n >> target;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  dfs(0, 0);
  cout<<cnt;
}