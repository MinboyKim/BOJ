#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, x, y, a, b;
int Visit[111];
vector<int> Edges[111];
queue<pii> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> a >> b >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        Edges[x].push_back(y);
        Edges[y].push_back(x);
    }

    q.push({a, 0});
    Visit[a] = 1;
    while (!q.empty()) {
        int dist = q.front().second;
        int cur = q.front().first;
        q.pop();
        if (cur == b) {
            cout << dist << "\n";
            return 0;
        }
        for (auto &i : Edges[cur])
            if (!Visit[i]) {
                Visit[i] = 1;
                q.push({i, dist + 1});
            }
    }

    cout << -1 << "\n";

    return 0;
}