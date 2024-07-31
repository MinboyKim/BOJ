#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    int aS = 100, bS = 100;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        if (a > b)
        {
            bS -= a;
        }
        else if (b > a)
        {
            aS -= b;
        }
    }
    cout << aS << '\n'
         << bS;
}