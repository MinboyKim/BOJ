#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    vector<int> v;

    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int maxL = min((v[0] + v[1] - 1), v[2]);

    cout<<maxL+v[0]+v[1];
}