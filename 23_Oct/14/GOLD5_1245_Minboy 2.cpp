#include <iostream>

using namespace std;

int Arr[111][77];
int ans, N, M;
int diff[2][8] = {{0, 0, -1, 1, -1, -1, 1, 1}, {-1, 1, 0, 0, -1, 1, -1, 1}};

void dfs(int r, int c, int v) {
    if (!Arr[r][c]) return;
    int temp = Arr[r][c];
    Arr[r][c] = 0;
    for (int i = 0; i < 8; i++) {
        int nr = r + diff[0][i];
        int nc = c + diff[1][i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        if (v >= Arr[nr][nc]) dfs(nr, nc, temp);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Arr[i][j];

    while (true) {
        int Max = 0, r, c;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (!Arr[i][j]) continue;
                if (Arr[i][j] > Max) {
                    r = i;
                    c = j;
                    Max = Arr[i][j];
                }
            }
        if (!Max) break;
        ans++;
        dfs(r, c, Max);
    }

    cout << ans << "\n";

    return 0;
}