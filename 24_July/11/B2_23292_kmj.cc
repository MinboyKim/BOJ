#include <bits/stdc++.h>

using namespace std;

int Max = -1;

int main()
{
    string a;
    int b;
    string c;
    string ans;
    cin >> a >> b;
    while (b--)
    {
        long long y = 0, m = 0, d = 0, res = 0;
        cin >> c;
        for (int i = 0; i < a.size(); i++)
        {
            if (i < 4)
            {
                y += pow(a[i] - c[i], 2);
            }
            else if (i < 6)
            {
                m += pow(a[i] - c[i], 2);
            }
            else
            {
                d += pow(a[i] - c[i], 2);
            }
        }
        res = y * m * d;
        if (res > Max)
        {
            Max = res;
            ans = c;
        }
        else if (res == Max)
        {
            if (stoi(ans) > stoi(c))
            {
                ans = c;
            }
        }
    }
    cout << ans;
}