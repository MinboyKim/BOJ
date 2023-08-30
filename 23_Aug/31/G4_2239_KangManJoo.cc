#include <bits/stdc++.h>

using namespace std;

int board[10][10];

void isExistInGroup(int i, int j) {}

void isExistInRow(int row) {}

void isExistInCol(int col) {}

int main() {
  string s;
  for (int i = 0; i < 9; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      board[i][j] = s[j];
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j]) continue;
      isExistInGroup(i, j);
      isExistInRow(i);
      isExistInCol(j);
    }
  }
}