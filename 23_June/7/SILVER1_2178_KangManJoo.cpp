#include <bits/stdc++.h>

using namespace std;

int board[102][102];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[102][102];
int cnt[102][102];
int n, m;
queue<pair<int, int>> q;

void bfs()
{
    int nextX;
    int nextY;
    while (1)
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == n - 1 && y == m - 1)
        {
            cout << cnt[n - 1][m - 1];
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nextX = x + dx[i];
            nextY = y + dy[i];
            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
                continue;
            if (!visited[nextX][nextY] && board[nextX][nextY] == 1)
            {
                cnt[nextX][nextY] = cnt[x][y] + 1;
                visited[nextX][nextY] = 1;
                q.push({nextX, nextY});
            }
        }
    }
}

int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = s[j] - 48;
        }
    }
    q.push({0, 0});
    visited[0][0] = 1;
    cnt[0][0] = 1;
    bfs();
}