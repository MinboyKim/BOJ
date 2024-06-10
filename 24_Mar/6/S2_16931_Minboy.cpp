#include <iostream>

using namespace std;

int N, M, ans;
int Arr[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    ans += N * M * 2;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> Arr[i][j];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 4; k++) {
                int nr = i + diff[0][k];
                int nc = j + diff[1][k];
                if (Arr[i][j] > Arr[nr][nc]) ans += Arr[i][j] - Arr[nr][nc];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}