#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

vector<pii> Edges[30];
int dist[30];
int T;
string s;
unordered_map<char, int> m;

void makeGraph() {
    Edges[0].push_back({1, 2});
    for (int i = 1; i <= 8; i++) {
        Edges[i].push_back({i - 1, 2});
        Edges[i].push_back({i + 1, 2});
    }
    Edges[9].push_back({8, 2});
    Edges[10].push_back({11, 2});
    for (int i = 11; i <= 17; i++) {
        Edges[i].push_back({i - 1, 2});
        Edges[i].push_back({i + 1, 2});
    }
    Edges[18].push_back({17, 2});
    Edges[19].push_back({20, 2});
    for (int i = 20; i <= 24; i++) {
        Edges[i].push_back({i - 1, 2});
        Edges[i].push_back({i + 1, 2});
    }
    Edges[25].push_back({24, 2});
    Edges[0].push_back({10, 2});
    for (int i = 1; i <= 8; i++) {
        Edges[i].push_back({i + 9, 2});
        Edges[i].push_back({i + 10, 2});
    }
    Edges[9].push_back({18, 2});
    Edges[10].push_back({0, 2});
    Edges[10].push_back({1, 2});
    Edges[10].push_back({19, 2});
    for (int i = 11; i <= 17; i++) {
        Edges[i].push_back({i - 10, 2});
        Edges[i].push_back({i - 9, 2});
        Edges[i].push_back({i + 8, 2});
        Edges[i].push_back({i + 9, 2});
    }
    Edges[18].push_back({8, 2});
    Edges[18].push_back({9, 2});
    Edges[19].push_back({10, 2});
    Edges[19].push_back({11, 2});
    for (int i = 20; i <= 25; i++) {
        Edges[i].push_back({i - 9, 2});
        Edges[i].push_back({i - 8, 2});
    }
}

int dijkstra(int start, int end) {
    for (int i = 0; i <= 25; i++)
        dist[i] = 999'999'999;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
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
    return dist[end];
}

void makeMap() {
    m.insert({'Q', 0});
    m.insert({'W', 1});
    m.insert({'E', 2});
    m.insert({'R', 3});
    m.insert({'T', 4});
    m.insert({'Y', 5});
    m.insert({'U', 6});
    m.insert({'I', 7});
    m.insert({'O', 8});
    m.insert({'P', 9});
    m.insert({'A', 10});
    m.insert({'S', 11});
    m.insert({'D', 12});
    m.insert({'F', 13});
    m.insert({'G', 14});
    m.insert({'H', 15});
    m.insert({'J', 16});
    m.insert({'K', 17});
    m.insert({'L', 18});
    m.insert({'Z', 19});
    m.insert({'X', 20});
    m.insert({'C', 21});
    m.insert({'V', 22});
    m.insert({'B', 23});
    m.insert({'N', 24});
    m.insert({'M', 25});
}

void solve() {
    int ans = 1;
    for (int i = 1; i < s.length(); i++) {
        ans++;
        if (s[i] == s[i - 1]) continue;
        ans += dijkstra(m[s[i - 1]], m[s[i]]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    makeGraph();
    makeMap();

    cin >> T;
    while (T--) {
        cin >> s;
        solve();
    }

    return 0;
}