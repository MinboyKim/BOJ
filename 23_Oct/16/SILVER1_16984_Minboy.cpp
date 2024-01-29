#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;

queue<tiii> q;
int Arr[222][222];
int Visit[222][222];
int diff[2][6] = {{-2, -2, 0, 0, 2, 2}, {-1, 1, -2, 2, -1, 1}};
int N, r1, c1, r2, c2;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> r1 >> c1 >> r2 >> c2;

    q.push({r1, c1, 0});
    while (!q.empty()) {
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int cost = get<2>(q.front());
        if (r == r2 && c == c2) {
            cout << cost << "\n";
            return 0;
        }
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nr = r + diff[0][i];
            int nc = c + diff[1][i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (Visit[nr][nc]) continue;
            Visit[nr][nc] = 1;
            q.push({nr, nc, cost + 1});
        }
    }

    cout << -1 << "\n";

    return 0;
}