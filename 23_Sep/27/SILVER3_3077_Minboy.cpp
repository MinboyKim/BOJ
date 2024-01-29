#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, ans;
unordered_map<string, int> m;
string hw[2555];

bool check(int i, int j) {
    if (m[hw[i]] < m[hw[j]]) return true;
    return false;
}

void solve() {
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (check(i, j)) ans++;

    cout << ans << "/" << N * (N - 1) / 2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        m[s] = i;
    }
    for (int i = 0; i < N; i++)
        cin >> hw[i];

    solve();

    return 0;
}