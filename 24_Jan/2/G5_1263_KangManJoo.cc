#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii arr[1001];

bool cmp(pii a, pii b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    int t, endT;
    for (int i = 0; i < n; i++) {
        cin >> t >> endT;
        arr[i].first = t;
        arr[i].second = endT;
    }

    sort(arr, arr + n, cmp);

    int startT = arr[0].second - arr[0].first;
    int curT = arr[0].second;
    for (int i = 1; i < n; i++) {
        t = arr[i].first;
        endT = arr[i].second;
        if (curT + t > endT) {
            startT -= (curT + t) - endT;
            curT = endT;
        } else {
            curT += t;
        }
        if (startT < 0)
            break;
    }
    if (startT < 0)
        cout << -1;
    else
        cout << startT;
}