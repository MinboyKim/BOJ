#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> edge[100100];
int visited[100100];
int n, m, start, dest, cost, ansStart, ansDest;

void init() {
    for (int i = 0; i < 100100; i++) {
        visited[i] = 0;
    }
}

bool dfs(int w, int loc) {
    if (loc == ansDest) {
        return true;
    }

    for (int i = 0; i < edge[loc].size(); i++) {
        pii nextLoc = edge[loc][i];
        if (nextLoc.second < w || visited[nextLoc.first]) {
            continue;
        }
        visited[nextLoc.first] = 1;
        bool result = dfs(w, nextLoc.first);
        if (result)
            return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> start >> dest >> cost;
        edge[start].push_back({dest, cost});
        edge[dest].push_back({start, cost});
    }

    cin >> ansStart >> ansDest;

    int left = 0;
    int right = 1'000'000'001;

    while (left < right) {
        init();
        int mid = (left + right) / 2;
        if (dfs(mid, ansStart)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << right - 1;
}