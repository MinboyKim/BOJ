#include <iostream>
#include <string>

using namespace std;

string s1, s2;
int ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s1 >> s2;

    if (s1.length() != s2.length()) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) break;
        if (s1[i] == '8' && s2[i] == '8') ans++;
    }

    cout << ans << "\n";

    return 0;
}