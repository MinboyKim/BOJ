#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int t, n, m;
    cin >> t;

    while (t--) {

        cin >> n >> m;

        int res = 1, tmp = 1;
        for (int i = m; i > n; i--) {
            res *= i;
            res /= tmp;
            tmp++;
        }
        cout << res << '\n';
    }
}