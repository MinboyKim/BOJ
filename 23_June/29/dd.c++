#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    double mod = (100 - b) / 100;

    if (a * mod >= 100)
        cout << 0;
    else
        cout << 1;
}