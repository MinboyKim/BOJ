#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<string, int> book;
int N, ans;
string s;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    book[s]++;
  }

  for (auto &i : book) ans = max(ans, i.second);
  for (auto &i : book)
    if (ans == i.second) {
      cout << i.first << "\n";
      return 0;
    }

  return 0;
}