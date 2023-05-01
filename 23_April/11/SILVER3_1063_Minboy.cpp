#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int N;
int board[8][8];
pii king, stone;

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  string s1, s2;
  cin >> s1 >> s2 >> N;
  king.first = s1[0] - 'A';
  king.second = 7 - (s1[1] - '0' - 1);
  stone.first = s2[0] - 'A';
  stone.second = 7 - (s2[1] - '0' - 1);

  string cmd;
  for (int i = 0; i < N; i++) {
    cin >> cmd;
    if (cmd == "R") {
      if (king.first + 1 >= 8) continue;
      if (king.first + 1 == stone.first && king.second == stone.second) {
        if (stone.first + 1 >= 8) continue;
        king.first++;
        stone.first++;
      } else
        king.first++;
    } else if (cmd == "L") {
      if (king.first - 1 < 0) continue;
      if (king.first - 1 == stone.first && king.second == stone.second) {
        if (stone.first - 1 < 0) continue;
        king.first--;
        stone.first--;
      } else
        king.first--;
    } else if (cmd == "B") {
      if (king.second + 1 >= 8) continue;
      if (king.second + 1 == stone.second && king.first == stone.first) {
        if (stone.second + 1 >= 8) continue;
        king.second++;
        stone.second++;
      } else
        king.second++;
    } else if (cmd == "T") {
      if (king.second - 1 < 0) continue;
      if (king.second - 1 == stone.second && king.first == stone.first) {
        if (stone.second - 1 < 0) continue;
        king.second--;
        stone.second--;
      } else
        king.second--;
    } else if (cmd == "RT") {
      if (king.first + 1 >= 8 || king.second - 1 < 0) continue;
      if (king.first + 1 == stone.first && king.second - 1 == stone.second) {
        if (stone.first + 1 >= 8 || stone.second - 1 < 0) continue;
        king.first++;
        king.second--;
        stone.first++;
        stone.second--;

      } else {
        king.first++;
        king.second--;
      }
    } else if (cmd == "LT") {
      if (king.first - 1 < 0 || king.second - 1 < 0) continue;
      if (king.first - 1 == stone.first && king.second - 1 == stone.second) {
        if (stone.first - 1 < 0 || stone.second - 1 < 0) continue;
        king.first--;
        king.second--;
        stone.first--;
        stone.second--;
      } else {
        king.first--;
        king.second--;
      }
    } else if (cmd == "RB") {
      if (king.first + 1 >= 8 || king.second + 1 >= 8) continue;
      if (king.first + 1 == stone.first && king.second + 1 == stone.second) {
        if (stone.first + 1 >= 8 || stone.second + 1 >= 8) continue;
        king.first++;
        king.second++;
        stone.first++;
        stone.second++;
      } else {
        king.first++;
        king.second++;
      }
    } else {
      if (king.first - 1 < 0 || king.second + 1 >= 8) continue;
      if (king.first - 1 == stone.first && king.second + 1 == stone.second) {
        if (stone.first - 1 < 0 || stone.second + 1 >= 8) continue;
        king.first--;
        king.second++;
        stone.first--;
        stone.second++;
      } else {
        king.first--;
        king.second++;
      }
    }
  }

  cout << static_cast<char>(king.first + 'A') << 8 - king.second << "\n";
  cout << static_cast<char>(stone.first + 'A') << 8 - stone.second << "\n";

  return 0;
}