#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << '\n';
    sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    sum *= sum;
    cout << sum << '\n';
    sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i * i * i;
    }
    cout << sum << '\n';
    sum = 0;
}