#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> Edges[1010];
int degree[1010];
int result[1010];
int temp[1010];
queue<int> q;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  int c;
  for (int i = 0; i < M; i++) {
    cin >> c;
    for (int j = 0; j < c; j++) cin >> temp[j];
    for (int j = 0; j < c; j++)
      for (int k = j + 1; k < c; k++) {
        Edges[temp[j]].push_back(temp[k]);
        degree[temp[k]]++;
      }
  }

  for (int i = 1; i <= N; i++)
    if (!degree[i]) q.push(i);

  for (int i = 1; i <= N; i++) {
    if (q.empty()) {
      cout << 0 << "\n";
      return 0;
    }

    int cur = q.front();
    result[i] = cur;
    q.pop();
    for (auto &i : Edges[cur]) {
      degree[i]--;
      if (!degree[i]) q.push(i);
    }
  }

  for (int i = 1; i <= N; i++) cout << result[i] << "\n";

  return 0;
}