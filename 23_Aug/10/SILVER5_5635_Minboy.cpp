#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef pair<string, tuple<int, int, int>> pstiii;

bool compare(pstiii a, pstiii b) {
  if (get<2>(a.second) == get<2>(b.second)) {
    if (get<1>(a.second) == get<1>(b.second)) {
      return get<0>(a.second) > get<0>(b.second);
    }
    return get<1>(a.second) > get<1>(b.second);
  }
  return get<2>(a.second) > get<2>(b.second);
}

int n;
vector<pstiii> v;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  int a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> a >> b >> c;
    v.push_back({s, {a, b, c}});
  }

  sort(v.begin(), v.end(), compare);

  cout << v[0].first << "\n";
  cout << v[n - 1].first << "\n";

  return 0;
}