#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Arr[30][30];
int Visit[30][30];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
int N;
vector<int> v;

int dfs(int r, int c) {
    int ret = 1;
    Visit[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + diff[0][i];
        int nc = c + diff[1][i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        if (Arr[nr][nc] && !Visit[nr][nc]) ret += dfs(nr, nc);
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            Arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Arr[i][j] && !Visit[i][j]) v.push_back(dfs(i, j));
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto &i : v)
        cout << i << "\n";

    return 0;
}