#include <bits/stdc++.h>

using namespace std;
int arr[22][22];
int check[22][22];

int main()
{
    int t, row, col;
    string str, realStr;
    cin >> t;
    while (t--)
    {
        realStr = "";
        cin >> row >> col;
        cin >> str;

        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = str[cnt];
                cnt++;
            }
        }

        int direct = 0, curC = 0, curL = 0;

        while (1)
        {
            int cnt = 0;
            if (direct == 0)
            {
                for (int i = curC; i < col; i++)
                {
                    if (arr[curL][i] == 99)
                    {
                        break;
                    }
                    realStr += arr[curL][i];
                    arr[curL][i] = 99;
                    curC = i;
                    cnt++;
                }
                curL++;
            }
            if (direct == 1)
            {
                for (int i = curL; i < row; i++)
                {
                    if (arr[i][curC] == 99)
                    {
                        break;
                    }
                    realStr += arr[i][curC];
                    arr[i][curC] = 99;
                    curL = i;
                    cnt++;
                }
                curC--;
            }
            if (direct == 2)
            {
                for (int i = curC; i >= 0; i--)
                {
                    if (arr[curL][i] == 99)
                    {
                        break;
                    }
                    realStr += arr[curL][i];
                    arr[curL][i] = 99;
                    curC = i;
                }
                curL--;
            }
            if (direct == 3)
            {
                for (int i = curL; i >= 0; i--)
                {
                    if (arr[curL][i] == 99)
                    {
                        break;
                    }
                    realStr += arr[i][curC];
                    arr[i][curC] = 99;
                    curL = i;
                    cnt++;
                }
                curC++;
            }
            direct++;
            direct %= 4;

            if (cnt == 0)
            {
                break;
            }
        }
        cout << endl
             << realStr << endl;
    }
}