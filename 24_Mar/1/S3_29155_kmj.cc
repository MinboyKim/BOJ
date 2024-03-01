#include <bits/stdc++.h>

using namespace std;

vector<int> pb[5];

int pnum[5];

int main() {
    int n, pn, time, ans = 0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> pnum[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pn >> time;
        pb[pn-1].push_back(time);
    }

    for (int i = 0; i < 5; i++) {
        sort(pb[i].begin(), pb[i].end());
        for (int j = 0; j < pnum[i]; j++) {
            ans += pb[i][j];
            if (j != pnum[i] - 1) {
                ans += pb[i][j + 1] - pb[i][j];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (pnum[i])
            cnt++;
    }
    ans += (cnt - 1) * 60;

    cout << ans;
}