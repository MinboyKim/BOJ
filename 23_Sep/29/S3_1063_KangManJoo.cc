#include <bits/stdc++.h>

using namespace std;
int board[8][8];
int arr[9] = {0, 7, 6, 5, 4, 3, 2, 1, 0};
int ans[8] = {8, 7, 6, 5, 4, 3, 2, 1};

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    string k, s, q;
    int n, row, col, kRow, kCol;
    cin >> k >> s >> n;

    for (auto i : k) {
        if (i >= 65 && i <= 72) {
            kCol = i - 65;
        } else {
            kRow = arr[i - 48];
        }
    }
    board[kRow][kCol] = 1; // king

    for (auto i : s) {
        if (i >= 65 && i <= 72) {
            col = i - 65;
        } else {
            row = arr[i - 48];
        }
    }
    board[row][col] = 2; // stone

    while (n--) {
        cin >> q;

        if (q == "B") {
            if (kRow + 1 >= 8)
                continue;

            if (board[kRow + 1][kCol] == 2) {
                if (kRow + 2 >= 8)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kRow++;
                    board[kRow][kCol] = 1;
                    board[kRow + 1][kCol] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kRow++;
                board[kRow][kCol] = 1;
            }
        } else if (q == "T") {
            if (kRow - 1 < 0)
                continue;
            if (board[kRow - 1][kCol] == 2) {
                if (kRow - 2 < 0)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kRow--;
                    board[kRow][kCol] = 1;
                    board[kRow - 1][kCol] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kRow--;
                board[kRow][kCol] = 1;
            }
        } else if (q == "R") {
            if (kCol + 1 >= 8)
                continue;
            if (board[kRow][kCol + 1] == 2) {
                if (kCol + 2 >= 8)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kCol++;
                    board[kRow][kCol] = 1;
                    board[kRow][kCol + 1] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kCol++;
                board[kRow][kCol] = 1;
            }
        } else if (q == "L") {
            if (kCol - 1 < 0) {
                continue;
            }
            if (board[kRow][kCol - 1] == 2) {
                if (kCol - 2 < 0)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kCol--;
                    board[kRow][kCol] = 1;
                    board[kRow][kCol - 1] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kCol--;
                board[kRow][kCol] = 1;
            }
        } else if (q == "LB") {
            if (kRow + 1 >= 8 || kCol - 1 < 0)
                continue;
            if (board[kRow + 1][kCol - 1] == 2) {
                if (kRow + 2 >= 8 || kCol - 2 < 0)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kCol--;
                    kRow++;
                    board[kRow][kCol] = 1;
                    board[kRow + 1][kCol - 1] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kCol--;
                kRow++;
                board[kRow][kCol] = 1;
            }
        } else if (q == "LT") {
            if (kRow - 1 < 0 || kCol - 1 < 0)
                continue;
            if (board[kRow - 1][kCol - 1] == 2) {
                if (kRow - 2 < 0 || kCol - 2 < 0)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kCol--;
                    kRow--;
                    board[kRow][kCol] = 1;
                    board[kRow - 1][kCol - 1] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kCol--;
                kRow--;
                board[kRow][kCol] = 1;
            }
        } else if (q == "RB") {
            if (kRow + 1 >= 8 || kCol + 1 >= 8)
                continue;
            if (board[kRow + 1][kCol + 1] == 2) {
                if (kRow + 2 >= 8 || kCol + 2 >= 8)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kCol++;
                    kRow++;
                    board[kRow][kCol] = 1;
                    board[kRow + 1][kCol + 1] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kCol++;
                kRow++;
                board[kRow][kCol] = 1;
            }
        } else if (q == "RT") {
            if (kRow - 1 < 0 || kCol + 1 >= 8)
                continue;
            if (board[kRow - 1][kCol + 1] == 2) {
                if (kRow - 2 < 0 || kCol + 2 >= 8)
                    continue;
                else {
                    board[kRow][kCol] = 0;
                    kCol++;
                    kRow--;
                    board[kRow][kCol] = 1;
                    board[kRow - 1][kCol + 1] = 2;
                }
            } else {
                board[kRow][kCol] = 0;
                kCol++;
                kRow--;
                board[kRow][kCol] = 1;
            }
        }
    }

    k = "";
    s = "";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 1) {
                k += j + 65;
                k += ans[i] + 48;
            } else if (board[i][j] == 2) {
                s += j + 65;
                s += ans[i] + 48;
            }
        }
    }
    cout << k << endl;
    cout << s;
}