#include <iostream>

using namespace std;

int M, N, ans;
int Arr[300][300];
int diff[2][8] = {{-1, 0, 1, -1, 1, -1, 0, 1}, {-1, -1, -1, 0, 0, 1, 1, 1}};

void dfs(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + diff[0][i];
        int nc = c + diff[1][i];
        if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
        if (Arr[nr][nc]) {
            Arr[nr][nc] = 0;
            dfs(nr, nc);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> Arr[i][j];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (Arr[i][j]) {
                ans++;
                dfs(i, j);
            }

    cout << ans << "\n";

    return 0;
}