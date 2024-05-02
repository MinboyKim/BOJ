#include <bits/stdc++.h>

using namespace std;

string ispal(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return "false";
        }
    }
    return s;
}

int main() {
    int t, n, flag;
    string s;
    cin >> t;
    while (t--) {
        vector<string> li;
        flag = 0;
        cin >> n;
        while (n--) {
            cin >> s;
            li.push_back(s);
        }
        for (int i = 0; i < li.size(); i++) {
            for (int j = 0; j < li.size(); j++) {
                if(i==j){
                    continue;
                }
                string newS = li[i] + li[j];
                string ans = ispal(newS);
                if (ans != "false") {
                    cout << ans;
                    flag = 1;
                    break;
                };
            }
            if(flag){
                break;
            }
        }
        if (!flag) {
            cout << 0;
        }
        cout << '\n';
    }
}