#include <iostream>
#include <string>

using namespace std;

int N;
string s, input;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> s;
    int pos = s.find("*");
    string first = s.substr(0, pos);
    string last = s.substr(pos + 1);

    while (N--) {
        cin >> input;
        if (input.length() < first.length() + last.length()) {
            cout << "NE\n";
            continue;
        }
        string tempFirst = input.substr(0, first.length());
        string tempLast = input.substr(input.length() - last.length());
        if (tempFirst == first && tempLast == last)
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}