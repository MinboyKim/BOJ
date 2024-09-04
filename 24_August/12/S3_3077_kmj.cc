#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<string> ans;

int main()
{
    int n;
    string str;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        mp[str] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        ans.push_back(str);
    }

    int score = 0;

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = i + 1; j < ans.size(); j++)
        {
            if (mp[ans[i]] < mp[ans[j]])
            {
                score++;
            }
        }
    }

    int full = n * (n - 1) / 2;

    cout << score << "/" << full;
}