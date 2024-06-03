#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == 'C') {
                    for (int k = j + 1; k < s.length(); k++) {
                        if (s[k] == 'P') {
                            for (int u = k + 1; u < s.length(); u++) {
                                if (s[u] == 'C') {
                                    cout << "I love UCPC\n";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "I hate UCPC\n";

    return 0;
}