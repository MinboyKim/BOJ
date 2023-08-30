#include <bits/stdc++.h>

using namespace std;
long long dice[6];
long long result;

int main() {
  // 3개 = 4개
  // 2개 = 4 + (N-2)*8
  // 1개 = 4 * (N-1) * (N-2) + (N-2) *(N-2) -맨위
  // 3개 면이 가능한 경우의 수 0,5 2,3 1,4 같이 있는것만 제외

  long long N, min = 51, secondMin = 110, tripleMin = 155, Max = 0;
  cin >> N;
  for (int i = 0; i < 6; i++) {
    cin >> dice[i];
    if (dice[i] < min) min = dice[i];
  }

  if (N == 1) {
    for (int i = 0; i < 6; i++) {
      if (dice[i] > Max) Max = dice[i];
    }
    for (int i = 0; i < 6; i++) {
      result += dice[i];
    }
    cout << result - Max;
    return 0;
  }

  result += min * (4 * (N - 1) * (N - 2) + (N - 2) * (N - 2));

  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (i == 0 && j == 5 || i == 2 && j == 3 || i == 1 && j == 4) continue;
      if (dice[i] + dice[j] < secondMin) secondMin = dice[i] + dice[j];
    }
  }
  result += (secondMin) * (4 + (N - 2) * 8);

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 6; k++) {
        if (i == 0 && k == 5 || i == 2 && j == 3 || j == 2 && k == 3 ||
            i == 1 && j == 4 || i == 1 && k == 4 || j == 1 && k == 4)
          continue;
        if (dice[i] + dice[j] + dice[k] < tripleMin)
          tripleMin = dice[i] + dice[j] + dice[k];
      }
    }
  }

  result += tripleMin * 4;

  cout << result;
}