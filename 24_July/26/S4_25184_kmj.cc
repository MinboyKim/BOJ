#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;
    int d = n / 2;
    if(n%2!=0){
        d++;
    }
    int rd = n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << d - cnt << ' ';
        }
        else
        {
            cout << rd - cnt << ' ';
            cnt++;
        }
    }
}