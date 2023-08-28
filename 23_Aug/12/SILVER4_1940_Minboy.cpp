#include <iostream>
#include <unordered_set>

using namespace std;

int N, M, ans;
unordered_set<int> s;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  int a;

  for (int i = 0; i < N; i++) {
    cin >> a;
    s.insert(a);
  }

  for (auto i = s.begin(); i != s.end(); i++) {
    auto j = s.find(M - (*i));
    if (j != s.end()) ans++;
  }

  cout << ans / 2 << "\n";

  return 0;
}