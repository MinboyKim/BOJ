#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            cout << char(s[i] - 'a' + 'A');
        else
            cout << char(s[i] - 'A' + 'a');
    }

    return 0;
}