#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    int ans;
    for (int i = 0; i <= c; i++)
    {
        ans = a / b;
        a = a % b * 10;
    }

    cout << ans;
}