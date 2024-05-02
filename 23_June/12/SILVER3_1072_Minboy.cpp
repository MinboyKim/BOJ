#include <iostream>

using namespace std;

typedef long long ll;

ll X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> X >> Y;
    Z = (Y * 100) / X;
    if (Z == 99 || Z == 100)
    {
        cout << -1 << "\n";
        return 0;
    }

    ll left = 0, right = 1000000000, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (((Y + mid) * 100) / (X + mid) > Z)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left << "\n";

    return 0;
}