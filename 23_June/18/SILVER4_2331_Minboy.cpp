#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int A, P;
unordered_map<int, int> m;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> A >> P;
  m.insert({A, 1});
  int cnt = 2;
  string s = to_string(A);
  while (true) {
    int temp = 0;
    for (int i = 0; i < s.length(); i++) {
      temp += pow(s[i] - '0', P);
    }
    if (m.find(temp) != m.end()) {
      cout << m[temp] - 1 << "\n";
      return 0;
    }
    m.insert({temp, cnt});
    cnt++;
    s = to_string(temp);
  }

  return 0;
}