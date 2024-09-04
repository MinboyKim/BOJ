#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    int t;
    cin >> t;
    while (t--)
    {
        int i = 0;
        vector<int> v;
        cin >> n;
        while (n)
        {
            if (n & 1)
            {
                v.push_back(i);
            }
            n >>= 1;
            i++;
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }

        cout << '\n';
    }
}