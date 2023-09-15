#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n, s, m;
int arr[51];
int dpMemo[51][1001];

void dp(int i, int cost) {
    if (i == n) {
        v.push_back(cost);
        return;
    }

    if(dpMemo[i][cost]) return;
    dpMemo[i][cost]=1;

    if (arr[i] + cost <= m)
        dp(i + 1, arr[i] + cost);
    if (cost-arr[i] >= 0)
        dp(i + 1, cost-arr[i]);
}

int main() {
    cin >> n >> s >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp(0, s);

    if (v.empty())
        cout << -1;
    else {
        sort(v.begin(),v.end(),greater<>());
        cout << v[0];
    }
}