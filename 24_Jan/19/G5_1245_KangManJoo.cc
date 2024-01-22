#include <bits/stdc++.h>

using namespace std;

int arr[102][102];
int visited[102][102];
int result;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int dfs(int row, int col) {
    visited[row][col] = 1;
    int result = 1;
    int valid = 1;
    for (int i = 0; i < 8; i++) {
        int nextRow = row + dy[i];
        int nextCol = col + dx[i];
        if (arr[row][col] > arr[nextRow][nextCol])
            continue;
        else if (arr[row][col] == arr[nextRow][nextCol]) {
            if(visited[nextRow][nextCol])
                continue;
            int dfsResult = dfs(nextRow, nextCol);
            if (!dfsResult)
                valid = 0;
            else {
                dfs(nextRow, nextCol);
            }
        } else if (arr[row][col] < arr[nextRow][nextCol]) {
            valid = 0;
        }
    }
    if (valid)
        return 1;
    else {
        return 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && arr[i][j]) {
                result += dfs(i, j);
            }
        }
    }

    cout << result;
}