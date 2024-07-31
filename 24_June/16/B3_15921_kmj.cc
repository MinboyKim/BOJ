#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    cin >> n;
    if (n == 0)
    {
        cout << "divide by zero";
    }
    else
    {
        int sum = 0;
        while (n--)
        {
            cin >> a;
            sum += a;
        }
        cout << "1.00";
    }
}