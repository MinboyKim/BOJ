#include <iostream>

using namespace std;

int N, M, a, b, ans;
int check[222][222];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        check[a][b] = 1;
        check[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (check[i][j]) continue;
            for (int k = j + 1; k <= N; k++) {
                if (check[i][k] || check[j][k]) continue;
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}