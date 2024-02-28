#include <bits/stdc++.h>

using namespace std;
int train[100100];
int check[3001000];
int main() {
    int n, m, cmd, tNum, loc, bosu;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> cmd >> tNum;
        switch (cmd) {
        case 1:
            cin >> loc;
            train[tNum] = train[tNum] | int(pow(2, loc - 1));
            break;
        case 2:
            cin >> loc;
            bosu = ~int(pow(2, loc - 1));
            train[tNum] = train[tNum] & bosu;
            break;
        case 3:
            train[tNum] = train[tNum] << 1;
            bosu = ~int(pow(2, 20));
            train[tNum] = train[tNum] & bosu;
            break;
        case 4:
            train[tNum] = train[tNum] >> 1;
            bosu = ~int(pow(2, 20));
            train[tNum] = train[tNum] & bosu;
            break;
        default:
            break;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[train[i]]) {
            cnt++;
            check[train[i]] = 1;
        }
    }
    cout << cnt;
}
