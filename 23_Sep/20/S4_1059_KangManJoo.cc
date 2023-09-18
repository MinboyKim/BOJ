#include <bits/stdc++.h>

using namespace std;

int arr[51];
int main() {
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> t;
    int pre, next;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (arr[i] > t) {
            if (i == 0)
                pre = 1;
            else
                pre = arr[i - 1] + 1;
            next = arr[i];
            break;
        }
    }
    if (pre > t) {
        cout << 0;

    } else {
        int ans = 0;
        while (pre <= t) {
            ans += next - t;
            pre++;
        }
        cout << ans - 1;
    }
}