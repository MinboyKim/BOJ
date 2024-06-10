#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a;
    cin >> n >> k >> a;

    int t, s;

    int mint = INT_MAX;

    while (n--)
    {
        cin >> t >> s;

        int drinkT = k / (a * t);
        if (k % (a * t) != 0)
        {
            drinkT *= s;
        }
        else
        {
            drinkT--;
            drinkT *= s;
        }
        drinkT += (k/a);
        if(k%a!=0)
        {
            drinkT++;
        }
        if (drinkT < mint)
        {
            mint = drinkT;
        }
    }

    cout << mint;
}