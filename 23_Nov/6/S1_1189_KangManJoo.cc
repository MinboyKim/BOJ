#include <bits/stdc++.h>

using namespace std;

char board[10][10];
int r, c, k;
int visited[10][10];
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int row, int col, int cnt) {
    if (row == 0 && col == (c - 1)) {
        if (cnt == k) {
            ans++;
        }
        return;
    }

    int nRow, nCol;
    for (int i = 0; i < 4; i++) {
        nCol = col + dx[i];
        nRow = row + dy[i];
        if (nCol < 0 || nCol >= c || nRow < 0 || nRow >= r)
            continue;
        if (board[nRow][nCol] == 'T' || visited[nRow][nCol])
            continue;
        visited[nRow][nCol] = 1;
        dfs(nRow, nCol, cnt + 1);
        visited[nRow][nCol] = 0;
    }
}

int main() {
    char t;
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    visited[r - 1][0] = 1;
    dfs(r - 1, 0, 1);

    cout << ans;
}