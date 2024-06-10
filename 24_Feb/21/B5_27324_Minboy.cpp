#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;

    cout << (s[0] == s[1] ? 1 : 0) << "\n";

    return 0;
}