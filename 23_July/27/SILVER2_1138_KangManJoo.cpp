#include <bits/stdc++.h>

using namespace std;
int n, i, j;
int leftBigger;
int loc[11];
int line[11];

int main() {
  cin >> n;


  for (i = 1; i <= n; i++) {
    cin >> leftBigger;

    for (j = 1; j <= leftBigger; j++) {
      if (loc[j]) {
        leftBigger++;
      }
    }
    loc[i] = j;
    line[j] = i;
  }

  for (i = 0; i < n; i++) {
    cout << line[i] << " ";
  }

}  // namespace std;
