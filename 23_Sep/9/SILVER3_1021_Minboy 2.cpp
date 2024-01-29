#include <deque>
#include <iostream>
#include <vector>

using namespace std;

deque<int> dq;
int ans, N, M;

void left() {
  int temp = dq.front();
  dq.pop_front();
  dq.push_back(temp);
  ans++;
}

void right() {
  int temp = dq.back();
  dq.pop_back();
  dq.push_front(temp);
  ans++;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) dq.push_back(i);

  int a;
  while (M--) {
    cin >> a;

    int id;
    for (int i = 0; i < dq.size(); i++)
      if (dq[i] == a) {
        id = i;
        break;
      }

    if (dq.size() - id < id) {
      while (dq[0] != a) right();
      dq.pop_front();
    } else {
      while (dq[0] != a) left();
      dq.pop_front();
    }
  }

  cout << ans << "\n";

  return 0;
}