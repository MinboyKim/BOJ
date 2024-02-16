#include <iostream>

using namespace std;

int R, C;
char Arr[255][255];
bool Visit[255][255];
int sheep, wolf;
int sheepTemp, wolfTemp;
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

void dfs(int r, int c) {
    Visit[r][c] = 1;
    if (Arr[r][c] == '#')
        return;
    else if (Arr[r][c] == 'o')
        sheepTemp++;
    else if (Arr[r][c] == 'v')
        wolfTemp++;
    for (int i = 0; i < 4; i++) {
        int nr = r + diff[0][i];
        int nc = c + diff[1][i];
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        if (!Visit[nr][nc]) dfs(nr, nc);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> Arr[i][j];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            sheepTemp = 0;
            wolfTemp = 0;
            if (!Visit[i][j]) dfs(i, j);
            if (sheepTemp > wolfTemp)
                sheep += sheepTemp;
            else
                wolf += wolfTemp;
        }

    cout << sheep << " " << wolf << "\n";

    return 0;
}