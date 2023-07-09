#include <bits/stdc++.h>

using namespace std;

int n, i, j;
int board[21][21];
int board2[21][21];
vector<int> cmdList;
int MAX;

// 0 = up  /  1 = down  /  2 = left /  3 = right

void play(int cmd) {
  int flag = 0;
  if (cmd == 0) {
    for (int j = 0; j < n; j++) {
      flag = 0;
      for (int i = 1; i < n; i++) {
        int cur = i;
        while (cur) {
          if (board2[cur][j] == 0) break;
          if (board2[cur - 1][j] == 0) {
            board2[cur - 1][j] = board2[cur][j];
            board2[cur][j] = 0;
          } else if (board2[cur - 1][j] == board2[cur][j]) {
            if (flag == 0) {
              board2[cur - 1][j] *= 2;
              board2[cur][j] = 0;
              flag = 1;
            } else {
              flag = 0;
            }
            break;
          } else {
            flag = 0;
            break;
          }
          cur--;
        }
      }
    }

  } else if (cmd == 1) {
    for (int j = 0; j < n; j++) {
      flag = 0;
      for (int i = n - 2; i >= 0; i--) {
        int cur = i;
        while (cur < n - 1) {
          if (board2[cur][j] == 0) break;
          if (board2[cur + 1][j] == 0) {
            board2[cur + 1][j] = board2[cur][j];
            board2[cur][j] = 0;
          } else if (board2[cur + 1][j] == board2[cur][j]) {
            if (flag == 0) {
              board2[cur + 1][j] *= 2;
              board2[cur][j] = 0;
              flag = 1;
            } else {
              flag = 0;
            }
            break;
          } else {
            flag = 0;
            break;
          }
          cur++;
        }
      }
    }
  } else if (cmd == 2) {
    for (int i = 0; i < n; i++) {
      flag = 0;
      for (int j = 1; j < n; j++) {
        int cur = j;
        while (cur) {
          if (board2[i][cur] == 0) break;
          if (board2[i][cur - 1] == 0) {
            board2[i][cur - 1] = board2[i][cur];
            board2[i][cur] = 0;
          } else if (board2[i][cur - 1] == board2[i][cur]) {
            if (flag == 0) {
              board2[i][cur - 1] *= 2;
              board2[i][cur] = 0;
              flag = 1;
            } else {
              flag = 0;
            }
            break;
          } else {
            flag = 0;
            break;
          }
          cur--;
        }
      }
    }
  } else if (cmd == 3) {
    for (int i = 0; i < n; i++) {
      flag = 0;
      for (int j = n - 2; j >= 0; j--) {
        int cur = j;
        while (cur < n - 1) {
          if (board2[i][cur] == 0) break;
          if (board2[i][cur + 1] == 0) {
            board2[i][cur + 1] = board2[i][cur];
            board2[i][cur] = 0;
          } else if (board2[i][cur + 1] == board2[i][cur]) {
            if (flag == 0) {
              board2[i][cur + 1] *= 2;
              board2[i][cur] = 0;
              flag = 1;
            } else {
              flag = 0;
            }
            break;
          } else {
            flag = 0;
            break;
          }
          cur++;
        }
      }
    }
  }
}

void dfs() {
  if (cmdList.size() == 5) {
    for (int i = 0; i < 21; i++) {
      for (int j = 0; j < 21; j++) {
        board2[i][j] = board[i][j];
      }
    }
    for (int i = 0; i < 5; i++) {
      play(cmdList[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board2[i][j] > MAX) MAX = board2[i][j];
      }
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    cmdList.push_back(i);
    dfs();
    cmdList.pop_back();
  }
}

int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  dfs();
  cout << MAX;
}