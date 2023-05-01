#include <deque>
#include <iostream>

using namespace std;

deque<int> dq;
int N;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) dq.push_back(i);

  for (int i = 0; i < N - 1; i++) {
    cout << dq.front() << " ";
    dq.pop_front();
    int temp = dq.front();
    dq.pop_front();
    dq.push_back(temp);
  }
  cout << dq.front() << "\n";

  return 0;
}