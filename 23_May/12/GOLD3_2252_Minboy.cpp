#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> Edges[32030];
int degree[32030];
queue<int> q;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    Edges[A].push_back(B);
    degree[B]++;
  }

  for (int i = 1; i <= N; i++)
    if (!degree[i]) q.push(i);

  for (int i = 0; i < N; i++) {
    int cur = q.front();
    cout << cur << " ";
    q.pop();
    for (auto &i : Edges[cur]) {
      degree[i]--;
      if (!degree[i]) q.push(i);
    }
  }

  return 0;
}