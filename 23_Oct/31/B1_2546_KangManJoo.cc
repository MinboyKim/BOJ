#include <bits/stdc++.h>

using namespace std;

double arr[200020], arr2[200020];
double sum1, sum2;
int t, n, m;
int binary1(double cur, int l, int r) {
    int mid = (l + r) / 2;
    if (l > r) {
        return l;
    }

    if (arr[mid] < cur) {
        return binary1(cur, mid + 1, r);
    } else if (arr[mid] > cur) {
        return binary1(cur, l, mid - 1);
    } else {
        return mid;
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        memset(arr, 0, 200020);
        memset(arr2, 0, 200020);
        cin >> n >> m;
        sum1 = 0;
        sum2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum1 += arr[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
            sum2 += arr2[i];
        }
        sum1 = sum1 / n;
        sum2 = sum2 / m;
        int k = n;
        int cnt = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) {
            if (arr[i] >= sum1) {
                k = i;
                break;
            }
        }
        for (int i = 0; i < k; i++) {
            if (arr[i] > sum2) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}