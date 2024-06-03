#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
char Arr[5][5];
unordered_set<string> us;

void dfs(int r, int c, string s) {
    if (s.length() == 6) {
        us.insert(s);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + diff[0][i];
        int nc = c + diff[1][i];
        if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
        dfs(nr, nc, s + Arr[nr][nc]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> Arr[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dfs(i, j, "");

    cout << us.size() << "\n";

    return 0;
}