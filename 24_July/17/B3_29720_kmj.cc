#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mi = a - b * c;
    int ma = a % b - 1;

    int maxAns = a-(b*(c-1)+1);

    if (mi < 0)
    {
        mi = 0;
    }

    cout << mi << " " << maxAns;
}