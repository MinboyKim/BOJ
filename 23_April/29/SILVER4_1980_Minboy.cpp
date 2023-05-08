#include <iostream>

using namespace std;

int n, m, t;
int ansHam, ansCoke = 999'999'999;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> n >> m >> t;

  for (int i = t / n; i >= 0; i--) {
    for (int j = t / m; j >= 0; j--) {
      int temp = i * n + j * m;
      if (t >= temp)
        if (ansCoke > t - temp) {
          ansCoke = t - temp;
          ansHam = i + j;
        } else if (ansCoke == t - temp) {
          if (ansHam < i + j) ansHam = i + j;
        }
    }
  }

  cout << ansHam << " " << ansCoke << "\n";

  return 0;
}