#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> v;
bool compare(pii a, pii b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return a.second < b.second;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int a, b;
  while (N--) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end(), compare);
  for (auto &i : v) cout << i.first << " " << i.second << "\n";

  return 0;
}