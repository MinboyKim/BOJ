#include <bits/stdc++.h>

using namespace std;

double t;
int dp[30][30];

double factorial(double x) {
  if (x == 1 || x == 0) {
    return 1;
  } else {
    return x * factorial(x - 1);
  }
}

int main() {
  double l, r;
  cin >> t;

   while (t--) {
    cin >> l >> r;
    // rCl
    double tmp = (factorial(r - l) * factorial(l));
     cout << factorial(r) << endl;
    cout << (factorial(r - l) * factorial(l))<<endl;
    cout << factorial(r) /tmp << '\n';
  }
  return 0;
}