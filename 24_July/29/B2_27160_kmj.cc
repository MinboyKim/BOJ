#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main()
{
    int t, a;
    cin >> t;
    mp.insert({"STRAWBERRY", 0});
    mp.insert({"BANANA", 0});
    mp.insert({"LIME", 0});
    mp.insert({"PLUM", 0});

    while (t--)
    {
        string str;
        cin >> str >> a;
        mp[str]+=a;
    }

    if (mp["STRAWBERRY"] == 5 || mp["BANANA"] == 5 || mp["LIME"] == 5 || mp["PLUM"] == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}