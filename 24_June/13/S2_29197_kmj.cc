#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

set<pair<int, int>> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int m = gcd(abs(a), abs(b));
        a /= m;
        b /= m;

        if (a < 0 && b >= 0)
        {
            a = abs(a)+10001;
            s.insert({a, b});
        }
        else if (a >= 0 && b < 0)
        {
            b = abs(b);
            s.insert({a, b+10001});
        }
        else if(a<0 && b<0)
        {
            s.insert({abs(a)+10001, abs(b)+10001});
        }
        else
        {
            s.insert({a, b});
        }
    }

    int cnt = 0;

    cout << s.size();
}
