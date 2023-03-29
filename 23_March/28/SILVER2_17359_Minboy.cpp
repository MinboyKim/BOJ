#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, fix, ans = 1'999'999'999;
string s;
vector<string> v;
vector<int> idx;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    v.push_back(s);
    for (int j = 1; j < s.length(); j++)
      if (s[j] != s[j - 1]) fix++;
  }

  for (int i = 0; i < N; i++) idx.push_back(i);

  do {
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
      if (v[idx[i]][v[idx[i]].size() - 1] != v[idx[i + 1]][0]) cnt++;
    }
    if (ans > cnt) ans = cnt;
  } while (next_permutation(idx.begin(), idx.end()));

  ans += fix;
  cout << ans << "\n";

  return 0;
}