#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int T, N, M;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T--) {
    int ans = 1;
    queue<pii> q;
    priority_queue<int> pq;
    cin >> N >> M;
    int a, target;
    for (int i = 0; i < N; i++) {
      cin >> a;
      if (i == M) {
        q.push({a, 1});
        target = a;
      } else
        q.push({a, 0});
      pq.push(a);
    }

    while (true) {
      while (pq.top() != q.front().first) {
        pii temp = q.front();
        q.pop();
        q.push(temp);
      }
      if (pq.top() != target) {
        ans++;
        q.pop();
        pq.pop();
      } else
        break;
    }

    while (q.front().second != 1) {
      if (q.front().first != target) {
        q.pop();
        continue;
      }
      ans++;
      q.pop();
    }
    cout << ans << "\n";
  }

  return 0;
}