#include <bits/stdc++.h>

using namespace std;
#define Mod 1'000'000'000

int N;
long long dp[101][11][1024];
long long result;

int main() {
  cin >> N;

  for (int i = 0; i < 10; i++) {
    int bit = 1 << i;

    dp[1][i][bit] = 1;
  }

  // i는 이전 길이
  for (int i = 1; i < N; i++) {
    // j는 이전 마지막 수
    for (int j = 0; j < 10; j++) {
      for (int bit = 0; bit < 1024; bit++) {
        int nextBit = bit | (1 << j);
        if (j == 0) {
          dp[i + 1][j][nextBit] += dp[i][j + 1][bit];
        } else if (j == 9) {
          dp[i + 1][j][nextBit] += dp[i][j - 1][bit];
        } else {
          dp[i + 1][j][nextBit] += dp[i][j + 1][bit];
          dp[i + 1][j][nextBit] += dp[i][j - 1][bit];
        }
        dp[i + 1][j + 1][nextBit] %= Mod;
        dp[i + 1][j - 1][nextBit] %= Mod;
      }
    }
  }

  for (int i = 1; i <= 9; i++) {
    result += dp[N][i][1023];
    result %= Mod;
  }

  cout << result;
}