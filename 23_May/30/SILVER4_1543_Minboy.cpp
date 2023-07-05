#include <iostream>
#include <string>

using namespace std;

string w, f;
int ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  getline(cin, w);
  getline(cin, f);
  for (int i = 0; i < w.length(); i++) {
    int flag = 0;
    for (int j = 0; j < f.length(); j++) {
      if (w[i + j] != f[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      ans++;
      i += f.length() - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}