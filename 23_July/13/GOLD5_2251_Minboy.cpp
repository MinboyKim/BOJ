#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tii;

int A, B, C;
queue<tii> q;
int Visit[222][222][222];
set<int> ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> B >> C;
  q.push({0, 0, C});

  while (!q.empty()) {
    tii cur = q.front();
    q.pop();
    int curA = get<0>(cur);
    int curB = get<1>(cur);
    int curC = get<2>(cur);
    if (Visit[curA][curB][curC]) continue;
    Visit[curA][curB][curC] = 1;

    if (!curA) ans.insert(curC);

    if (curA + curB > B)
      q.push({curA - (B - curB), B, curC});
    else
      q.push({0, curA + curB, curC});

    if (curA + curC > C)
      q.push({curA - (C - curC), curB, C});
    else
      q.push({0, curB, curA + curC});

    if (curB + curA > A)
      q.push({A, curB - (A - curA), curC});
    else
      q.push({curA + curB, 0, curC});

    if (curB + curC > C)
      q.push({curA, curB - (C - curC), C});
    else
      q.push({curA, 0, curB + curC});

    if (curC + curA > A)
      q.push({A, curB, curC - (A - curA)});
    else
      q.push({curA + curC, curB, 0});

    if (curC + curB > B)
      q.push({curA, B, curC - (B - curB)});
    else
      q.push({curA, curB + curC, 0});
  }

  for (auto &i : ans) cout << i << " ";

  return 0;
}