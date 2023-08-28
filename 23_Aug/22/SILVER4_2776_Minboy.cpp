#include <iostream>
#include <unordered_set>

using namespace std;

int T, N, M;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> T;
  while (T--) {
    unordered_set<int> s;
    int a;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> a;
      s.insert(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> a;
      auto it = s.find(a);
      if (it != s.end())
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    }
  }

  return 0;
}