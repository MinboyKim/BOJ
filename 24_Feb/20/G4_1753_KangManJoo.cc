#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> edge[20202];

int visited[20202];
int a, b;
int start, pNode, nNode, cost;

struct cmp {
    bool operator()(pii a, pii b) { return a.second > b.second; }
};

priority_queue<pii, vector<pii>, cmp> pq;

void dfs(int x, int cost) {
    visited[x] = cost;
    for (int i = 0; i < edge[x].size(); i++) {
        int nextNode = edge[x][i].first;
        int nextCost = edge[x][i].second;

        if (visited[nextNode])
            continue;
        else {
            pq.push({nextNode, nextCost + cost});
        }
    }

    while (!pq.empty()) {
        pii next = pq.top();
        pq.pop();
        if (visited[next.first] || next.first == start) {
            continue;
        } else {
            dfs(next.first, next.second);
            break;
        }
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> a >> b >> start;
    for (int i = 0; i < b; i++) {
        cin >> pNode >> nNode >> cost;
        int added = 0;
        for (int i = 0; i < edge[pNode].size(); i++) {
            if (edge[pNode][i].first == nNode) {
                edge[pNode][i].second = min(edge[pNode][i].second, cost);
                added = 1;
                break;
            }
        }
        if (!added)
            edge[pNode].push_back({nNode, cost});
    }

    dfs(start, 0);

    for (int i = 1; i <= a; i++) {
        if (i != start && visited[i] == 0) {
            cout << "INF" << '\n';
        } else
            cout << visited[i] << '\n';
    }
}