#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cur = 1, idx=0;
    while (true) {
        string curStr = to_string(cur);
        for (int j = 0; j < curStr.length(); j++) {
            if (curStr[j] == str[idx]) {
                idx++;
            }
        }
        cur++;
        if (idx == str.length())
            break;
    }
    cout << cur - 1;
}