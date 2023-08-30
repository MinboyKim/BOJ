#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, pii> dpii;
pii board[101];
priority_queue<dpii, vector<dpii>, greater<>> pq;
int visited[101];
double result;
int Union[101];

int n;
double x, y;

int findParent(int cur) {
  if (Union[cur] == cur) return cur;
  return findParent(Union[cur]);
}

void makeUnion(int a, int b) {
  a = findParent(a);
  b = findParent(b);

  Union[b] = a;
  return;
}

int main() {
  cin >> n;
  string x, y;

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    board[i].first = stod(x);
    board[i].second = stod(y);
    Union[i] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double dist = sqrt(pow(board[i].first - board[j].first, 2) +
                         pow(board[i].second - board[j].second, 2));
      dpii edge = {dist, {i, j}};
      pq.push(edge);
    }
  }

  while (!pq.empty()) {
    dpii cur = pq.top();
    pq.pop();
    int Pnode = cur.second.first;
    int Nnode = cur.second.second;

    if (findParent(Pnode) == findParent(Nnode)) continue;

    makeUnion(Pnode, Nnode);
    result += cur.first;
  }
  cout << fixed << setprecision(2) << result;
}