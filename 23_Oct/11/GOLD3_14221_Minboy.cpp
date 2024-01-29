#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> Edges[5555], ans;
unordered_set<int> house, conv;
int n, m, p, q, dist[5555];

void dijkstra() {
    for (int i = 1; i <= n; i++)
        dist[i] = 999'999'999;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto &i : conv)
        pq.push({0, i});
    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();
        if (curCost > dist[curVertex]) continue;
        for (auto &i : Edges[curVertex]) {
            int nextCost = i.second;
            int nextVertex = i.first;
            if (curCost + nextCost < dist[nextVertex]) {
                dist[nextVertex] = curCost + nextCost;
                pq.push({curCost + nextCost, nextVertex});
            }
        }
    }
    int tempCost = 999'999'999;
    int tempVertex = 0;
    for (int i = 1; i <= n; i++)
        if (dist[i] < tempCost && house.find(i) != house.end()) {
            tempCost = dist[i];
            tempVertex = i;
        }

    cout << tempVertex << "\n";
}

bool compare(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Edges[a].push_back({b, c});
        Edges[b].push_back({a, c});
    }

    cin >> p >> q;
    for (int i = 0; i < p; i++) {
        cin >> a;
        house.insert(a);
    }
    for (int i = 0; i < q; i++) {
        cin >> a;
        conv.insert(a);
    }

    dijkstra();

    return 0;
}