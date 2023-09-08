#include <bits/stdc++.h>

using namespace std;

int board[10][10];

bool isExistInGroup(int row, int col, int x) {
    int rowNum = row / 3;
    int colNum = col / 3;
    for (int i = rowNum * 3; i < rowNum + 3; i++) {
        for (int j = colNum * 3; j < colNum + 3; j++) {
            if (board[i][j] == x)
                return false;
        }
    }
    return true;
}

bool isExistInRow(int row, int x) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == x)
            return false;
    }
    return true;
}

bool isExistInCol(int col, int x) {
    for (int i = 0; i < 9; i++) {
            if (board[i][col] == x)
                return false;
    }
    return true;
}

void sudoku(int row, int col) {
    if (row >= 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
        exit(0);
    }

    for (int i = 1; i < 10; i++) {

        if (isExistInGroup(row, col, i) && isExistInRow(row, i) &&
            isExistInCol(col, i)) {
            board[row][col] = i;
            int nextRow = row;
            int nextCol = col;
            while (true) {
                if (nextCol < 8) {
                    nextCol += 1;
                } else {
                    nextRow += 1;
                    nextCol = 0;
                }
                if (board[nextRow][nextCol])
                    continue;
                else {
                    sudoku(nextRow, nextCol);
                    break;
                }
            }
        }
        board[row][col] = 0;
    }
    return;
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
            sudoku(i, j);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}