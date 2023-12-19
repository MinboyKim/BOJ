#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, q;
    int n;
    cin >> s >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> q;
        q = q + q;
        if (q.find(s) != string::npos) {
            cnt++;
        }
    }
    cout << cnt;
}