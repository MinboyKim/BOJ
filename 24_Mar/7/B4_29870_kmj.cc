#include <bits/stdc++.h>

using namespace std;

long long cost[6];
int main() {
    long long n, a, b, c, d, e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    a = cost[0];
    b = cost[1];
    c = cost[2];
    d = cost[3];
    e = cost[4];
    int cnt = 0;
    if (a > c) {
        cnt += abs(a - c) * 508;
    } else {
        cnt += abs(a - c) * 108;
    }
    if (b > d) {
        cnt += (b - d) * 212;
    } else {
        cnt += (d - b) * 305;
    }
    cnt += e * 707;
    cout << cnt*4763;
}