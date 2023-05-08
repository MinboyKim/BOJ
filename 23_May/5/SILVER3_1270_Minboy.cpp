#include <iostream>
#include <map>

using namespace std;

int n;

int main(void) {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    long long T, a;
    cin >> T;
    map<int, int> m;
    long long flag = 0;
    for (int j = 0; j < T; j++) {
      cin >> a;
      long long tmp = ++m[a];
      if (tmp > T / 2) flag = a;
    }
    if (!flag)
      cout << "SYJKGW\n";
    else
      cout << flag << "\n";
  }

  return 0;
}