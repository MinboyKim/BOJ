#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int cnt = 0;
        string s;
        getline(cin, s);
        if (s == "#")
            break;
        else {
            for (auto i : s) {
                if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'||i=='A'||i=='E'||i=='I'||i=='O'||i=='U')
                    cnt++;
            }
            cout << cnt << endl;
        }

    }
}