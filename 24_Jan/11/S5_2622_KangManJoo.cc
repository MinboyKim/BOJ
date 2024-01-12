#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            k = n - i - j;
            if (i > k || j > k)
                break;
            if (i + j > k)
                cnt++;
        }
        if (i > k)
            break;
    }
    cout << cnt;
}