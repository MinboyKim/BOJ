#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  for (auto &i : v) cout << i.first << " " << i.second << "\n";

  return 0;
}