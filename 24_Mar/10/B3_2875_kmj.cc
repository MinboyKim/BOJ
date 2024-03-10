#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    while (k--) {
        int a = n / 2;
        int b = m;
        if (a >= b) {
            n--;
        } else {
            m--;
        }
    }
    int a = n / 2;
    int b = m;
    cout << min(a, b);
}