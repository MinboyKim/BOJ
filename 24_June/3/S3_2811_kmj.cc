#include <bits/stdc++.h>

using namespace std;

int arr[100100];
int flower[100100];
vector<int> maxV;

int main()
{
    int n, val;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;

    int MaxIdx = 0, MaxCnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            cnt = 0;
            continue;
        }
        else
        {
            cnt++;
            if ((i - cnt * 3 + 2) >= 0)
                flower[i - cnt * 3 + 2] = 1;
            if ((i - cnt * 3 + 1) >= 0)
                flower[i - cnt * 3 + 1] = 1;
        }
        if (cnt == MaxCnt)
        {
            maxV.push_back(i);
        }
        if (cnt > MaxCnt)
        {
            MaxCnt = cnt;
            maxV.clear();
            maxV.push_back(i);
        }
    }

    int maxB=0;

    for (auto idx : maxV)
    {
        int cost = MaxCnt * 3;
        int bonus = 0;
        for (int i = idx - MaxCnt; i >= 0; i--)
        {
            if(flower[i]==0){
                bonus++;
            }
            cost--;
            if (cost <= 0)
            {
                break;
            }
        }
        maxB = max(maxB, bonus);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (flower[i])
        {
            ans++;
        }
    }
    cout << ans+maxB;
}