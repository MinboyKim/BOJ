#include <iostream>

using namespace std;

typedef pair<int, int> pii;

pii Arr[10][10];

void erase(int a) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      if (Arr[i][j].first == a) {
        Arr[i][j].second = 1;
        return;
      }
}

int check() {
  int cnt = 0;
  int flag = 0;
  for (int i = 0; i < 5; i++) {
    flag = 0;
    for (int j = 0; j < 5; j++) {
      if (Arr[i][j].second == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) cnt++;
  }

  for (int i = 0; i < 5; i++) {
    flag = 0;
    for (int j = 0; j < 5; j++) {
      if (Arr[j][i].second == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) cnt++;
  }

  flag = 0;
  for (int i = 0; i < 5; i++) {
    if (Arr[i][i].second == 0) {
      flag = 1;
      break;
    }
  }
  if (!flag) cnt++;

  flag = 0;
  for (int i = 4; i >= 0; i--) {
    if (Arr[i][4 - i].second == 0) {
      flag = 1;
      break;
    }
  }
  if (!flag) cnt++;

  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      cin >> a;
      Arr[i][j] = {a, 0};
    }

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      cin >> a;
      erase(a);
      int b = check();
      if (b >= 3) {
        cout << i * 5 + j + 1 << "\n";
        return 0;
      }
    }

  return 0;
}