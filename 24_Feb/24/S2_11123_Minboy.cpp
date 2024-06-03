#include <iostream>
#include <string>

using namespace std;

int T, H, W, ans;
string s;
char Arr[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

void dfs(int r, int c) {
    Arr[r][c] = '.';
    for (int i = 0; i < 4; i++) {
        int nr = r + diff[0][i];
        int nc = c + diff[1][i];
        if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
        if (Arr[nr][nc] == '#') dfs(nr, nc);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    while (T--) {
        ans = 0;
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            cin >> s;
            for (int j = 0; j < W; j++)
                Arr[i][j] = s[j];
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (Arr[i][j] == '#') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}