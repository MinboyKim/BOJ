#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> Edges[32020];
int degree[32020];
int result[32020];
priority_queue<int, vector<int>, greater<int>> q;

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

  for (int i = 1; i <= N; i++) {
    int cur = q.top();
    q.pop();
    result[i] = cur;
    for (auto &j : Edges[cur]) {
      degree[j]--;
      if (!degree[j]) q.push(j);
    }
  }

  for (int i = 1; i <= N; i++) cout << result[i] << " ";

  return 0;
}