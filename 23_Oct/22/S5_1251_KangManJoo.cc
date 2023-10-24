#include <bits/stdc++.h>

using namespace std;

int MIN = 999;
int idx;

string reverse(string s) {
    string tmp = "";

    for (int i = s.length() - 1; i >= 0; i--) {
        tmp += s[i];
    }
    s = tmp;
    return s;
}

int main() {
    string s;
    string a, b, c;
    cin >> s;
    string ans = "", tmp;

    for (int i = 1; i < s.length() - 1; i++) {
        for (int j = 1; j < s.length() - i; j++) {
            tmp = "";
            a = s.substr(0, i);
            b = s.substr(i, j);
            c = s.substr(i + j);
            a = reverse(a);
            b = reverse(b);
            c = reverse(c);
            tmp = a + b + c;
            if (ans > tmp || ans == "")
                ans = tmp;
        }
    }

    cout << ans;
}