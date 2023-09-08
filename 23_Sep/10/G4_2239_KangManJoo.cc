#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int board[10][10];

struct cmp {
    bool operator()(pii a, pii b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

bool isExist(int row, int col, int x) {
    for (int i = 0; i < 9; i++) {
        if (i != row && board[i][col] == x)
            return true;
        if (i != col && board[row][i] == x)
            return true;
    }
    int rowG = (row / 3) * 3;
    int colG = (col / 3) * 3;
    for (int i = rowG; i < rowG + 3; i++) {
        for (int j = colG; j < colG + 3; j++) {
            if (i == row && j == col)
                continue;
            if (board[i][j] == x)
                return true;
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    exit(0);
}

void sudoku(int row, int col) {

    for (int i = 1; i <= 9; i++) {
        board[row][col] = i;
        if (!isExist(row, col, i)) {
            if (pq.empty()) {
                solve();
            }
            pii next = pq.top();
            pq.pop();
            sudoku(next.first, next.second);
        }
        board[row][col] = 0;
    }
    pq.push({row, col});
}

int main() {
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            board[i][j] = s[j] - 48;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j])
                continue;
            else {
                pq.push({i, j});
            }
        }
    }
    pii next = pq.top();
    pq.pop();
    sudoku(next.first, next.second);
}