#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  int a;
  while (true) {
    cin >> a;
    if (a == -1)
      break;
    else if (a == 0 && !q.empty())
      q.pop();
    else if (q.size() < N)
      q.push(a);
  }

  if (q.empty()) cout << "empty\n";

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}