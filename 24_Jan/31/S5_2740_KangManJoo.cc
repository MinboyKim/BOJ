#include <bits/stdc++.h>

using namespace std;

int a[101][101];
int b[101][101];
int result[101][101];

int main() {
    int n, m;
    int k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    int tmp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            tmp = 0;
            for (int t = 0; t < m; t++) {
                tmp += a[i][t] * b[t][j];
            }
            result[i][j] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}