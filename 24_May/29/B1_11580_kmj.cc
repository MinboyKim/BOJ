#include <bits/stdc++.h>

using namespace std;

int board[2002][2002];

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int curC = 1000, curR = 1000;
    board[curR][curC] = 1;
    for (auto c : str)
    {
        if (c == 'S')
        {
            curR--;
        }
        if (c == 'E')
        {
            curC++;
        }
        if (c == 'N')
        {
            curR++;
        }
        if (c == 'W')
        {
            curC--;
        }
        board[curR][curC] = 1;
    }

    int cnt = 0;

    for (int i = 0; i < 2002; i++)
    {
        for (int j = 0; j < 2002; j++)
        {
            if (board[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}