#include <bits/stdc++.h>

using namespace std;
#define MAX 10000000

long long n, tByte;
typedef pair<int, int> pii;
pii arr[101];
long long board[101][10101];
int minCost = 2000000000;

bool cmp(pii a, pii b)
{
    return a.second < b.second;
}
int main()
{
    cin >> n >> tByte;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }

    sort(arr, arr + n, cmp);

    for (int i = arr[0].second; i <= 10101; i++)
    {
        board[0][i] = arr[0].first;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 10101; j++)
        {
            int curByte = arr[i].first;
            int curCost = arr[i].second;
            if (j - curCost >= 0)
            {
                board[i][j] = max(board[i - 1][j], board[i - 1][j - curCost] + curByte);
            }
            else
            {
                board[i][j] = board[i - 1][j];
            }
        }
    }

     for (int i = 0; i <= 10101; i++)
	{
		if (board[n-1][i] >= tByte)
		{
			cout << i << endl;
			break;
		}	
	}
}