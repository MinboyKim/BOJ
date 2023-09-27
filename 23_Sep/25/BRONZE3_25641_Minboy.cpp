#include <iostream>
#include <string>

using namespace std;

string s;
int N, sausage, tteok;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 's')
      sausage++;
    else
      tteok++;

  if (sausage == tteok) {
    cout << s << "\n";
    return 0;
  }

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 's')
      sausage--;
    else
      tteok--;
    if (sausage == tteok) {
      for (int j = i + 1; j < s.length(); j++) cout << s[j];
      cout << "\n";
      return 0;
    }
  }

  return 0;
}