#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> node[1001001];
int visited[1001001];
int finished[1001001];
int sum;

void dfs(int cur) {
  visited[cur] = 1;
  for (int i = 0; i < node[cur].size(); i++) {
    int next = node[cur][i];
    if (finished[next]) continue;
    if (visited[next] && !finished[next]) {
      sum++;
    } else {
      dfs(next);
    }
  }
  finished[cur] = 1;
}

int main() {
  cin >> n >> m;

  for (int row = 0; row < n; row++) {
    int cur = m * row;
    string s;

    cin >> s;
    for (auto a : s) {
      if (a == 'D') {
        int next = cur + m;
        node[cur].push_back(next);
      } else if (a == 'L') {
        int next = cur - 1;
        node[cur].push_back(next);
      } else if (a == 'R') {
        int next = cur + 1;
        node[cur].push_back(next);
      } else if (a == 'U') {
        int next = cur - m;
        node[cur].push_back(next);
      }
      cur++;
    }
  }
  for (int i = 0; i < m * n; i++) {
    if (!finished[i]) dfs(i);
  }
  cout << sum;
}