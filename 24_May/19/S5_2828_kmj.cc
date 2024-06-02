#include <bits/stdc++.h>

using namespace std;

int block[21];
vector<int> v;

int main()
{
    int n, m, num, loc;
    cin >> n >> m;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> loc;
        v.push_back(loc);
    }

    int left = 1;
    int right = m;

    int cnt = 0;

    for (auto loc : v)
    {
        if (loc < left)
        {
            cnt += left - loc;
            left = loc;
            right = left + m - 1;
        }
        else if (loc > right)
        {
            cnt += loc - right;
            right = loc;
            left = right - m + 1;
        }
        else
        {
            continue;
        }
    }

    cout << cnt;
}