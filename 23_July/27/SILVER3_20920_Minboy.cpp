#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<string, int> pii;

int N, M;
unordered_map<string, int> m;

bool compare(pii a, pii b) {
  if (a.second == b.second) {
    if (a.first.length() == b.first.length()) return a.first < b.first;
    return a.first.length() > b.first.length();
  }
  return a.second > b.second;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (s.length() < M) continue;
    m[s]++;
  }
  vector<pii> ans(m.begin(), m.end());
  sort(ans.begin(), ans.end(), compare);
  for (auto& i : ans) cout << i.first << "\n";

  return 0;
}
