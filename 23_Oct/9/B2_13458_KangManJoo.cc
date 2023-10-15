#include <bits/stdc++.h>

using namespace std;

int arr[1000010];
long long total;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, b, c;

    cin >> n;
    int a;
    for (int j = 0; j < n; j++) {
        cin >> arr[j];
    }
    cin >> b >> c;
    for (int j = 0; j < n; j++) {
        arr[j] -= b;
        total++;
        if (arr[j] > 0) {
            total += arr[j] / c;
            if (arr[j] % c != 0)
                total++;
        }
    }
    cout << total;
}