#include <iostream>

using namespace std;

int main() {
  int n, b;
  int cnt = 1;
  while (true) {
    cin >> n;
    if (!n) break;
    while (n--) {
      cin >> b;
    }
    cout << "Case " <<cnt<<": Sorting... done!"<<'\n';
    cnt++;
  }
}