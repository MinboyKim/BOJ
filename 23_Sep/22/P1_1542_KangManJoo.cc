#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<int> v;

// 홀수번 = 그런디수 1 짝수번 = 그런디수 0
int board[101][101];
int n = 5, q, x, y;

void init() {
    while (!v.empty())
        v.pop_back();
}

void initBoard() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            board[i][j] = -1;
        }
    }

    int cnt = 1;
    for (int i = 1; i < 100; i++) {
        for (int j = 1; j < 100; j++) {
            if (board[i][j] == 0)
                break;
            if (j - i == cnt) {
                board[i][j] = 0;
                board[j][i] = 0;
                cnt++;
                break;
            }
        }
    }

    int preBoard;
    for (int i = 1; i < 100; i++) {
        for (int j = 1; j < 100; j++) {
            if (!board[i][j] || i == j)
                continue;
            board[i][j] = max(board[i - 1][j], board[i][j - 1]) + 1;
        }
    }
}

int main() {
    initBoard();

    while (n--) {
        init();


        cin >> q;
        int result = 0;
        bool endGmae = false;
        while (q--) {
            cin >> x >> y;
            if (board[x][y] == -1)
                endGmae = true;
            result = result ^ board[x][y];
        }

        if (result || endGmae)
            cout << "S";
        else
            cout << "D";
        cout << '\n';
    }
}