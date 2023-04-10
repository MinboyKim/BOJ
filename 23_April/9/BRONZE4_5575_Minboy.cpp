#include <iostream>

using namespace std;

int sum, ans, h, m, s;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int a, b, c;
  for (int i = 0; i < 3; i++) {
    sum = ans = 0;
    cin >> a >> b >> c;
    sum += a * 3600 + b * 60 + c;
    cin >> a >> b >> c;
    ans += a * 3600 + b * 60 + c;
    ans -= sum;
    h = ans / 3600;
    ans %= 3600;
    m = ans / 60;
    ans %= 60;
    s = ans;
    cout << h << " " << m << " " << s << "\n";
  }

  return 0;
}