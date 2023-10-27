#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int T, a, b;

pii destruct(int a) {
  int temp = a;
  int id = 0;
  while (true) {
    id++;
    temp -= id;
    if (temp <= 0) break;
  }
  int hold = 0;
  for (int i = 1; i <= id; i++) hold += i;
  return {id - (hold - a), 1 + (hold - a)};
}

int bind(int a, int b) {
  int diff = b - 1;
  int id = a + b - 1;
  int hold = 0;
  for (int i = 1; i <= id; i++) hold += i;
  return hold - diff;
}

void solve(int a, int b) {
  pii cod1 = destruct(a);
  pii cod2 = destruct(b);
  cout << bind(cod1.first + cod2.first, cod1.second + cod2.second) << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    cin >> a >> b;
    solve(a, b);
  }

  return 0;
}