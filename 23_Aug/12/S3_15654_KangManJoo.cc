#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[10];
vector<int> v;
int visited[10];

void dfs(int cur, int cnt) {
  if (cnt == m) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    if(!visited[i]){
      visited[i]=1;
      v.push_back(arr[i]);
      dfs(i, cnt + 1);
      visited[i]=0;
      v.pop_back();
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  dfs(-1, 0);
}