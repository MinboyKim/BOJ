#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--)
    {
        string n;
        int a;
        cin >> a;
        int cnt = 0;
        while (a != 6174)
        {
            cnt++;
            n = to_string(a);
            if(n.size() < 4)
            {
                n += "0";
            }
            for (auto i : n)
            {
                v.push_back(i - '0');
            }
            sort(v.begin(), v.end(), greater<int>());

            int maxA = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];

            sort(v.begin(), v.end());

            int minA = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];

            v.clear();

            a = maxA - minA;
        }
        cout << cnt << '\n';
    }
}