#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, bool> com;
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  string s1, s2;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    if (s2 == "enter")
      com[s1] = true;
    else
      com[s1] = false;
  }

  for (auto i = com.rbegin(); i != com.rend(); i++)
    if (i->second == true) cout << i->first << "\n";

  return 0;
}