#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> node[33000];
int degree[33000];
int lv[33000];
typedef pair<int, int> pii;
vector<pair<int, int>> answer;



int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> n >> m;
    int Pnode, Nnode;
    while (m--)
    {
        cin >> Pnode >> Nnode;
        node[Pnode].push_back(Nnode);
        degree[Nnode]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!degree[i])
        {
            q.push(i);
            lv[i] = 0;
        }
    }

    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < node[cur].size(); i++)
        {
            int next = node[cur][i];
            degree[next]--;
            if (!degree[next])
            {
                q.push(next);
            }
        }
    }
}