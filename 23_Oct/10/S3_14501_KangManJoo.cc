#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii jobs[21];
int arr[16];
int n, ans;

int dp(int cur) {
    if (cur >= n)
        return 0;
    if (jobs[cur].first + cur > n)
        return dp(cur + 1);
    else
        return max(jobs[cur].second + dp(cur + jobs[cur].first), dp(cur + 1));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }
    int finish;
    ans += dp(0);

    cout << ans;
}