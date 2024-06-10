#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> Edges[101'010];
int ans[101'010];
bool Visit[101'010];
int cnt = 1, N, M, R, u, v;
queue<int> q;

void bfs(int node) {
    Visit[node] = true;
    q.push(node);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans[cur] = cnt;
        cnt++;
        for (auto &i : Edges[cur])
            if (!Visit[i]) {
                Visit[i] = true;
                q.push(i);
            }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(Edges[i].begin(), Edges[i].end(), greater<int>());
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}