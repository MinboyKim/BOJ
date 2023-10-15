#include <bits/stdc++.h>

using namespace std;

int n, m, s, a, hole;
int rabbit[101010];
int rabbithole[1000];

void solve() {
    cin >> s >> a;
    int sum = 0;

    while (s) {
        if (a % hole == 1 && s >= hole) {
            s -= hole;
            a += hole;
            rabbithole[a / hole]++;
            sum += rabbithole[a / hole];
        } else if (a == n - n % hole + 1 && s == n % hole) {
            s = 0;
            a += hole;
            rabbithole[a / hole]++;
            sum += rabbithole[a / hole];
        } else {
            s--;
            a++;
            rabbit[a]++;
            sum += rabbit[a];
        }
    }
    cout << sum << '\n';
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n >> m;
    hole = sqrt(n);
    while (m--) {
        solve();
    }
}