#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, k, l, second;
int board[102][102];  // 0 = nothing 1=snake 2=apple
deque<pii> snake;

void init() {
  for (int i = 0; i <= n + 1; i++) {
    board[i][0] = 1;
    board[0][i] = 1;
    board[n + 1][i] = 1;
    board[i][n + 1] = 1;
  }
}

int main() {
  cin >> n >> k;
  int row, col;

  while (k--) {
    cin >> row >> col;
    board[row][col] = 2;  // apple
  }

  init();

  int moveCnt;
  char cmd;
  snake.push_back({1, 1});
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int preDirect = 3;
  int direct = 3;
  cin >> l;
  int preMoveCnt = 0;

  int nextDx;
  int nextDy;
  while (l--) {
    cin >> moveCnt >> cmd;

    nextDx = dx[direct];
    nextDy = dy[direct];
    int tmp = moveCnt;
    moveCnt -= preMoveCnt;
    preMoveCnt = tmp;
    while (moveCnt--) {
      second++;
      pii tail;
      pii head = snake.front();
      pii next = {head.first + nextDx, head.second + nextDy};
      int NX = next.first;
      int NY = next.second;
      tail = snake.back();
      snake.pop_back();
      snake.push_front(next);
      if (board[NX][NY] == 0) {
        board[tail.first][tail.second] = 0;
        board[NX][NY] = 1;
      } else if (board[NX][NY] == 1) {
        cout << second;
        return 0;
      } else if (board[NX][NY] == 2) {
        if (NX == tail.first && NY == tail.second) {
          cout << second;
          return 0;
        }
        board[NX][NY] = 1;
        board[tail.first][tail.second] = 1;
        snake.push_back(tail);
      }
    }

    // 0=up 1=down 2= left 3=right
    if (cmd == 'D') {
      if (preDirect == 3) {
        preDirect = direct = 1;
      } else if (preDirect == 2) {
        preDirect = direct = 0;
      } else if (preDirect == 1) {
        preDirect = direct = 2;
      } else if (preDirect == 0) {
        preDirect = direct = 3;
      }
    } else if (cmd == 'L') {
      if (preDirect == 3) {
        preDirect = direct = 0;
      } else if (preDirect == 2) {
        preDirect = direct = 1;
      } else if (preDirect == 1) {
        preDirect = direct = 3;
      } else if (preDirect == 0) {
        preDirect = direct = 2;
      }
    }
  }

  nextDx = dx[direct];
  nextDy = dy[direct];
  while (true) {
    second++;
    pii tail;
    pii head = snake.front();
    pii next = {head.first + nextDx, head.second + nextDy};
    int NX = next.first;
    int NY = next.second;
    tail = snake.back();
    snake.pop_back();
    snake.push_front(next);
    board[tail.first][tail.second] = 0;
    if (board[NX][NY] == 0) {
      board[NX][NY] = 1;
    } else if (board[NX][NY] == 1) {
      cout << second;
      return 0;
    } else if (board[NX][NY] == 2) {
      if (NX == tail.first && NY == tail.second) {
        cout << second;
        return 0;
      }
      board[NX][NY] = 1;
      board[tail.first][tail.second] = 1;
      snake.push_back(tail);
    }
  }
  cout << second;

  return 0;
}