#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int check[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
long long wp, bp;

long long dfs(int y, int x) {
    check[y][x] = 1;
    long long power = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (!check[ny][nx] && (board[ny][nx] == board[y][x])) {
            power += dfs(ny, nx);
        }
    }
    return power;
}

int main() {
    string s;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j]) {
                if (board[i][j] == 'W')
                    wp += pow(dfs(i, j), 2);
                else {
                    bp += pow(dfs(i, j), 2);
                }
            }
        }
    }

    cout << wp << " " << bp;
}