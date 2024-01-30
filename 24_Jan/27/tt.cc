#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        b = a / 5;
        c = a % 5;
        for (int j = 0; j < b; j++) {
            cout << "++++ ";
        }
        for (int k = 0; k < c; k++) {
            cout << "l";
        }
        cout << "\n";
    }
}