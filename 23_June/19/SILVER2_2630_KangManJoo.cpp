#include <bits/stdc++.h>

using namespace std;

int n, whiteCnt, blueCnt;
int board[129][129];

void dfs(int x, int y, int cur)
{
    int flag = board[x][y];

    for (int i = x; i < x + cur; i++)
    {
        for (int j = y; j < y + cur; j++)
        {
            if (board[i][j] != flag)
            {
                int nextCur = cur / 2;
                dfs(x + nextCur, y, nextCur);
                dfs(x + nextCur, y + nextCur, nextCur);
                dfs(x, y + nextCur, nextCur);
                dfs(x, y, nextCur);
                return;
            }
        }
    }
    if (flag)
        blueCnt++;
    else
        whiteCnt++;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, n);

    cout << whiteCnt << '\n'
         << blueCnt;
}