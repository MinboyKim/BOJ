#include <bits/stdc++.h>

using namespace std;

string arr[101];
int cnt;
int value[150];

void init() {
  for (auto &i : value) {
    i = 0;
  }
}
int main() {
  int n;
  string s;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;
    init();
    char pre='A';
    int isGroup = 1;

    for (auto &c : s) {
      if (pre == c) {
        continue;
      }
      if (value[c] == 1) {
        isGroup = 0;
        break;
      }
      value[c] = 1;
      pre = c;
    }

    if (isGroup) cnt++;
  }

  cout << cnt;
}