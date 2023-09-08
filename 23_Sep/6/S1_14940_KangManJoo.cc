#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int board[1010][1010];
int n, m;
int destR, destC;
int visited[1001][1001];

queue<piii> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                destR = i;
                destC = j;
            }
            if (board[i][j] == 1) {
                board[i][j] = -1;
            }
        }
    }

    q.push({{destR, destC}, 0});

    while (!q.empty()) {
        piii cur = q.front();
        q.pop();
        int curR = cur.first.first;
        int curC = cur.first.second;
        int curCost = cur.second;
        board[curR][curC] = curCost;

        for (int i = 0; i < 4; i++) {
            int nextR = curR + dx[i];
            int nextC = curC + dy[i];
            if (visited[nextR][nextC])
                continue;
            if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m)
                continue;
            if (board[nextR][nextC] == 0)
                continue;
            visited[nextR][nextC] = 1;
            q.push({{nextR, nextC}, curCost + 1});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}