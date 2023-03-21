#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  cout << "<";
  for (int i = 1; i <= N; i++) q.push(i);
  while (q.size() > 1) {
    for (int i = 0; i < K - 1; i++) {
      int tmp = q.front();
      q.pop();
      q.push(tmp);
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << q.front() << ">";

  return 0;
}