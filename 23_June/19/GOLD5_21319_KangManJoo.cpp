#include <bits/stdc++.h>

using namespace std;
int n, m, len;
char board[51][51];
string str, name, answer;
typedef pair<int, int> pii;
int lvUP;

int main()
{
    cin >> n >> m >> len;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            board[i][j] = str[j];
        }
    }
    cin >> name;

    pii curLoc = {0, 0};
    queue<pii> q;

    while (true)
    {
        int cnt = 0;
        int find;
        while (cnt < len)
        {
            find = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == name[cnt])
                    {
                        board[i][j] = '0';
                        q.push({i, j});
                        cnt++;
                        find = 1;
                        break;
                    }
                }
                if (find == 1)
                    break;
            }
            if (find == 0)
            {
                break;
            }
        }
        if (find == 1)
        {
            while (!q.empty())
            {
                pii next = q.front();
                q.pop();
                if (curLoc.first < next.first)
                {
                    for (int i = 0; i < next.first - curLoc.first; i++)
                    {
                        answer += "D";
                    }
                }
                else
                {
                    for (int i = 0; i < curLoc.first - next.first; i++)
                    {
                        answer += "U";
                    }
                }
                if (curLoc.second < next.second)
                {
                    for (int i = 0; i < next.second - curLoc.second; i++)
                    {
                        answer += "R";
                    }
                }
                else
                {
                    for (int i = 0; i < curLoc.second - next.second; i++)
                    {
                        answer += "L";
                    }
                }
                answer += "P";
                curLoc = next;
            }
            lvUP++;
        }
        else
        {
            pii next = {n - 1, m - 1};
            for (int i = 0; i < next.first - curLoc.first; i++)
            {
                answer += "D";
            }
            for (int i = 0; i < next.second - curLoc.second; i++)
            {
                answer += "R";
            }
            break;
            // 현재위치에서 탈출점까지 이동
        }
    }
    cout << lvUP << " " << answer.length() << '\n'
         << answer;
}