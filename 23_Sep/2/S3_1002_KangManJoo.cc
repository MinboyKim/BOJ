#include <bits/stdc++.h>

using namespace std;

int main() {
  double t, x1, x2, y1, y2, r1, r2;
  cin >> t;
  while (t--) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (dist > r1 + r2)
      cout << 0;
    else if (dist == r1 + r2)
      cout << 1;
    else if (dist + r1 < r2) {
      cout << 0;
    } else if (dist + r2 < r1) {
      cout << 0;
    } else if (dist==0 && r1==r2) {
        cout<<-1;
    } else if (dist + r1 == r2) {
      cout << 1;
    } else if (dist + r2 == r1) {
      cout << 1;
    } else {
      cout << 2;
    }
    cout << '\n';
  }
}