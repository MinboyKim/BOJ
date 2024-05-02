#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    long long cnt = 0;
    cin >> a >> b;
    for (auto i : a)
    {
        for (auto j : b)
        {
            cnt += (i - '0') * (j - '0');
        }
    }
    cout << cnt;
}