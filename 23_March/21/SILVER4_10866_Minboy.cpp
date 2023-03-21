#include <deque>
#include <iostream>
#include <string>

using namespace std;

deque<int> dq;
string s;
int N;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int a;
  while (N--) {
    cin >> s;
    if (s == "push_front") {
      cin >> a;
      dq.push_front(a);
    } else if (s == "push_back") {
      cin >> a;
      dq.push_back(a);
    } else if (s == "pop_front") {
      if (dq.empty())
        cout << -1 << "\n";
      else {
        cout << dq.front() << "\n";
        dq.pop_front();
      }
    } else if (s == "pop_back") {
      if (dq.empty())
        cout << -1 << "\n";
      else {
        cout << dq.back() << "\n";
        dq.pop_back();
      }
    } else if (s == "size")
      cout << dq.size() << "\n";
    else if (s == "empty") {
      if (dq.empty())
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    } else if (s == "front") {
      if (dq.empty())
        cout << -1 << "\n";
      else
        cout << dq.front() << "\n";
    } else {
      if (dq.empty())
        cout << -1 << "\n";
      else
        cout << dq.back() << "\n";
    }
  }

  return 0;
}