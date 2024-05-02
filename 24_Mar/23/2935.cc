#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    char c;
    cin >> a >> c >> b;
    if (c == '+') {
        int al = a.length() - 1;
        int bl = b.length() - 1;
        if (al == bl) {
            cout << "2";
            for (int i = 0; i < al; i++) {
                cout << "0";
            }
        } else {
            cout << "1";
            int maxl = max(al, bl);
            int minl = min(al, bl);
            for (int i = 0; i < maxl; i++) {
                if (i == maxl - minl - 1) {
                    cout << "1";
                    continue;
                }
                cout << "0";
            }
        }
    }
    else {
        int al = a.length() - 1;
        int bl = b.length() - 1;

        cout << "1";
        for (int i = 0; i < al + bl; i++) {
            cout << "0";
        }
    }
}