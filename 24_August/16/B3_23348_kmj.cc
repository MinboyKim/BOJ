#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c;

    int n;
    cin >> n;
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> d >> e >> f;
            sum += a * d + b * e + c * f;
        }
        if (maxSum < sum)
            maxSum = sum;
    }
    cout << maxSum;
}