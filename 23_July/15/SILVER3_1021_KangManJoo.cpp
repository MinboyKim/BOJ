#include <bits/stdc++.h>

using namespace std;

queue<int> target;
int cnt, cost;

int main() {
  int n, m, t;
  deque<int> dq;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> t;
    target.push(t);
  }

  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }

  for (int i = 0; i < m; i++) {
    t = target.front();
    target.pop();
    int head = dq.front();
    if (t > head) {
      if (n - t + head > t - head) {
        while (head != t) {
            cost++;
            dq.pop_front();
            dq.push_back(head);
            head = dq.front();
        }
        dq.pop_front();
      }
      else{
        while (head != t) {
            cost++;
            dq.pop_back();
            dq.push_front(head);
            head = dq.front();
        }
        dq.pop_front();
      }
    }
    else{
      if (n - t + head > head > t) {
        while (head != t) {
            cost++;
            dq.pop_front();
            dq.push_back(head);
            head = dq.front();
        }
        dq.pop_front();
      } else {
        while (head != t) {
            cost++;
            dq.pop_back();
            dq.push_front(head);
            head = dq.front();
        }
        dq.pop_front();
      }
    }
  }
}