#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string s;
unordered_map<char, char> m;

void makeMap() {
    m.insert({'a', 'e'});
    m.insert({'i', 'o'});
    m.insert({'y', 'u'});
    m.insert({'e', 'a'});
    m.insert({'o', 'i'});
    m.insert({'u', 'y'});
    m.insert({'A', 'E'});
    m.insert({'I', 'O'});
    m.insert({'Y', 'U'});
    m.insert({'E', 'A'});
    m.insert({'O', 'I'});
    m.insert({'U', 'Y'});
    m.insert({'b', 'p'});
    m.insert({'k', 'v'});
    m.insert({'x', 'j'});
    m.insert({'z', 'q'});
    m.insert({'n', 't'});
    m.insert({'h', 's'});
    m.insert({'d', 'r'});
    m.insert({'c', 'l'});
    m.insert({'w', 'm'});
    m.insert({'g', 'f'});
    m.insert({'p', 'b'});
    m.insert({'v', 'k'});
    m.insert({'j', 'x'});
    m.insert({'q', 'z'});
    m.insert({'t', 'n'});
    m.insert({'s', 'h'});
    m.insert({'r', 'd'});
    m.insert({'l', 'c'});
    m.insert({'m', 'w'});
    m.insert({'f', 'g'});
    m.insert({'B', 'P'});
    m.insert({'K', 'V'});
    m.insert({'X', 'J'});
    m.insert({'Z', 'Q'});
    m.insert({'N', 'T'});
    m.insert({'H', 'S'});
    m.insert({'D', 'R'});
    m.insert({'C', 'L'});
    m.insert({'W', 'M'});
    m.insert({'G', 'F'});
    m.insert({'P', 'B'});
    m.insert({'V', 'K'});
    m.insert({'J', 'X'});
    m.insert({'Q', 'Z'});
    m.insert({'T', 'N'});
    m.insert({'S', 'H'});
    m.insert({'R', 'D'});
    m.insert({'L', 'C'});
    m.insert({'M', 'W'});
    m.insert({'F', 'G'});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    makeMap();
    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                cout << m[s[i]];
            else
                cout << s[i];
        }
        cout << "\n";
    }

    return 0;
}