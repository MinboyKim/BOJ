#include <iostream>

using namespace std;

double h, P;
double lamp1 = 5, lamp2 = 60;
int cnt = 1, day = 1, life = 1000;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> h >> P;

  while (true) {
    lamp1 += 60 * h * P / 100000;
    lamp2 += 11 * h * P / 100000;
    life -= h;
    if (life < 0) {
      life += 1000;
      lamp1 += 5;
      cnt++;
    }
    if (lamp1 > lamp2) {
      cout << day << "\n";
      return 0;
    }
    day++;
  }

  return 0;
}