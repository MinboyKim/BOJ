#include <iostream>
#include <string>

using namespace std;

string S;
string a = "KOREA", b = "YONSEI";
int c, d;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == a[c]) c++;
        if (S[i] == b[d]) d++;
        if (c == 5) {
            cout << a << "\n";
            return 0;
        }
        if (d == 6) {
            cout << b << "\n";
            return 0;
        }
    }

    return 0;
}