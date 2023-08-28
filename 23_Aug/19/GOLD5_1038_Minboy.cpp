#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
queue<long long> q;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  if (!N) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 1; i < 10; i++) q.push(i);

  int idx = 0;
  while (true) {
    long long now = q.front();
    q.pop();
    idx++;
    if (idx == N) {
      cout << now << "\n";
      return 0;
    }
    string ns = to_string(now);
    if (ns.length() >= 10) {
      cout << -1 << "\n";
      return 0;
    }
    for (int i = 0; i < ns[ns.length() - 1] - '0'; i++) {
      string next = ns + to_string(i);
      q.push(stoll(next));
    }
  }

  return 0;
}