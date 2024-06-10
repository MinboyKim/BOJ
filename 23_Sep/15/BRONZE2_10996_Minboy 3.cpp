#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  string s1 = "";
  string s2 = "";
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      s1 += "*";
      s2 += " ";
    } else {
      s1 += " ";
      s2 += "*";
    }
  }
  for (int i = 0; i < N; i++) {
    cout << s1 << "\n";
    cout << s2 << "\n";
  }

  return 0;
}