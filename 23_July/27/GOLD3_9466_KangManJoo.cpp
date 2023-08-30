#include <bits/stdc++.h>

using namespace std;

int t, n;
int student[100100];
int visited[100100];
stack<int> stk;
int result, rtn;
int checked[100100];

int dfs(int cur) {
  if (cur == student[cur]) {
    checked[cur]=1;
    visited[cur] = 1;
    result++;
    return cur;
  }



  if (!visited[cur]) {
    stk.push(cur);
    visited[cur] = 1;
    if (checked[student[cur]]) {
      return -1;
    }
    else rtn = dfs(student[cur]);  // 1 ->3
  } else {
    return cur;
  }

  int cnt = 0;
  if (rtn == cur) {
    while (!stk.empty()) {
      int top = stk.top();
      stk.pop();
      cnt++;
      checked[top] = 1;
      if (top == cur) break;
    }
  }

  result += cnt;

  return rtn;
}

void initStk() {
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
    checked[i] = 0;
  }
  while (!stk.empty()) {
    stk.pop();
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    result = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> student[i];
    }

    initStk();
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) dfs(i);
    }

    cout << n - result << '\n';
  }
  return 0;
}