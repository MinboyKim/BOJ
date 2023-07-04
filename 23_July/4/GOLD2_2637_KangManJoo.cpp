#include <bits/stdc++.h>

using namespace std;

int n, m, cur, curN, pre, preNum;
typedef pair<int, int> pii;
vector<pii> node[101];
int cnt[101];
int degree[101];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  int Pnode, Nnode, num;
  while (m--) {
    cin >> Nnode >> Pnode >> num;
    node[Nnode].push_back({Pnode, num});
    degree[Pnode]++;
  }

  queue<int> q;
  q.push(n);
  cnt[n] = 1;

  while (!q.empty()) {
    cur = q.front();
    curN = cnt[cur];
    q.pop();

    for (auto &p : node[cur]) {
      pre = p.first;
      preNum = p.second;

      if (node[pre].empty()) {
        cnt[pre] += curN * preNum;
      } else {
        degree[pre]--;
        cnt[pre] += curN * preNum;

        if (!degree[pre]) q.push(pre);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (node[i].empty()) {
      cout << i << " " << cnt[i] << '\n';
    }
  }
}