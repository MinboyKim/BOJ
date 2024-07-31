#include <bits/stdc++.h>

using namespace std;

int pascal[31][31];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == i || j == 1)
                pascal[i][j] = 1;
            else
            {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }

    int lv = 1;
    int cnt = 0;
    for (int i = a; i < a + c; i++)
    {
        for (int j = b; j < b + lv; j++){
            cnt+=pascal[i][j];
        }
        lv++;
    }
    cout<<cnt;
}