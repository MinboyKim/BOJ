#include <deque>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

deque<pii> dq;
int N;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  int temp;
  for (int i = 1; i <= N; i++) {
    cin >> temp;
    dq.push_back({i, temp});
  }

  while (!dq.empty()) {
    temp = dq.front().second;
    cout << dq.front().first << " ";
    dq.pop_front();
    if (temp < 0) {
      for (int i = 0; i < -1 * temp; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    } else {
      for (int i = 0; i < temp - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }
  }

  return 0;
}