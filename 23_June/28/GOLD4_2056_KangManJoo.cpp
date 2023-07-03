#include <bits/stdc++.h>

using namespace std;

vector<int> node[10101];
int cost[10101];
int degree[10101];
int nCost[10101];
queue<int> q;

int main()
{
    int n, t, Nnode;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i] >> t;
        nCost[i]=cost[i];
        while (t--)
        {
            cin >> Nnode;
            node[Nnode].push_back(i);
            degree[i]++;
        }
    }
    // 현재 degree가 0인 노드들은 전부 동시에 수행한다. 동시에 수행하는 개념은 어떻게?

    for (int i = 1; i <= n; i++)
    {
        if (!degree[i])
        {
            q.push(i);
        }
    }

    int cur;
    int maxcost = 0;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (nCost[cur] > maxcost)
            maxcost = nCost[cur];
        for (int i = 0; i < node[cur].size(); i++)
        {
            int next = node[cur][i];
            if (!nCost[next])
            {
                nCost[next] = nCost[cur] + cost[next];
            }
            else
            {
                nCost[next] = max(nCost[next], nCost[cur] + cost[next]);
            }
            degree[next]--;
            if (!degree[next])
            {
                q.push(next);
            }
        }
    }
    cout << maxcost;
}