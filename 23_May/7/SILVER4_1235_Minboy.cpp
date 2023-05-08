#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N;
string Arr[1010];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  int l = Arr[0].length();
  for (int i = 0; i < l; i++) {
    unordered_set<string> s;
    int flag = 1;
    for (int j = 0; j < N; j++) {
      string temp = Arr[j].substr(l - 1 - i);
      if (s.find(temp) == s.end())
        s.insert(temp);
      else {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << i + 1 << "\n";
      return 0;
    }
  }

  return 0;
}