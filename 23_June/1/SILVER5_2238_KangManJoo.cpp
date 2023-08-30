#include <bits/stdc++.h>

using namespace std;

int cost[100100];
map<int, string> mp;
int main()
{
    int n, m, k;
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> k;
        mp.insert({k,s});
        cost[k]++;
    }
    for(auto i: mp){
        if(cost[i.first]==1){
            cout<<i.second<<" "<<i.first;
            break;
        }
    }
    return 0;
}