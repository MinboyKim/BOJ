#include <iostream>
#include <string>

using namespace std;

char Arr[5][15];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  for (int i = 0; i < 5; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) Arr[i][j] = s[j];
  }

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      if (!Arr[j][i]) continue;
      cout << Arr[j][i];
    }
  }

  return 0;
}