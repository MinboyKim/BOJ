#include <bits/stdc++.h>

using namespace std;

bool isHan(string s) {
    int c;
    for (int i = 1; i < s.size(); i++) {
        if (i == 1)
            c = s[i] - s[i - 1];

        if (s[i] - s[i - 1] != c) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (isHan(to_string(i))) {
            cnt++;
        }
    }
    cout << cnt;
}