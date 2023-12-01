#include <bits/stdc++.h>

using namespace std;

char board[101][101];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int row = 0, col = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == 2) {
                row++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (board[j][i] == '.') {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == 2) {
                col++;
            }
        }
    }
    cout << row << " " << col;
}