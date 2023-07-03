#include <bits/stdc++.h>

using namespace std;

#define INF 1'999'999'999

int n, m, startP, endP;
int visited[1001];
typedef pair<int, int> pii;
vector<pii> node[1001];
int dist[1001];

struct cmp
{
    bool operator()(pii a, pii b)
    {
        return a.second > b.second; // pq는 오름차순시 관계연산자의 방향이 반대다.
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

void dijkstra(int cur, int curCost)
{
    visited[cur] = 1;
    dist[cur] = curCost;
    for (int i = 0; i < node[cur].size(); i++)
    {
        if (visited[node[cur][i].first])
            continue;
        node[cur][i].second += curCost;
        pq.push(node[cur][i]);
    }
    pii tmp;
    while (!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        if (visited[tmp.first])
            continue;
        else
            dijkstra(tmp.first, tmp.second);
    }
    return;
}

int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> n >> m;
    int Pnode, Nnode, cost;
    while (m--)
    {
        cin >> Pnode >> Nnode >> cost;
        node[Pnode].push_back({Nnode, cost});
    }
    cin >> startP >> endP;
    dist[startP] = 0;
    dijkstra(startP, 0);

    cout << dist[endP];

    return 0;
}
