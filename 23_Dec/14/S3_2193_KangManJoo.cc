#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

long long arr[91][2];

int main() {
    int n;
    cin >> n;

    int cur = 1;
    arr[0][1] = 1;

    for (int i = 1; i < n; i++) {
        arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
        arr[i][1] = arr[i - 1][0];
    }
    cout << arr[n - 1][0] + arr[n - 1][1];
}

// 1010 1001 1000
// 10101 10100 10010 10001 10010