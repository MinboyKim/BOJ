#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string s;

bool solve(int D) {
  unordered_set<string> set;
  int i = 0, cnt = 0;

  while (true) {
    if (s.length() > i + D + 1) {
      cnt++;
      string temp = "";
      set.insert(temp + s[i] + s[i + D + 1]);
    } else
      break;
    i++;
  }

  if (cnt == set.size()) return true;
  return false;
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  while (true) {
    cin >> s;
    if (s == "*") break;
    bool flag = true;
    for (int i = 0; i < s.length() - 1; i++) {
      if (!solve(i)) {
        flag = false;
        break;
      }
    }
    cout << s << " is" << (flag ? " surprising.\n" : " NOT surprising.\n");
  }

  return 0;
}