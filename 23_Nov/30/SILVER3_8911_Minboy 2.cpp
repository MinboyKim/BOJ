#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;

pii diff[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int T = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        int dir = 0, r = 0, c = 0;
        int minR = 0;
        int minC = 0;
        int maxR = 0;
        int maxC = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'F') {
                r += diff[dir].first;
                c += diff[dir].second;
            } else if (s[i] == 'B') {
                r += diff[dir].first * -1;
                c += diff[dir].second * -1;
            } else if (s[i] == 'L') {
                dir = (dir + 3) % 4;
            } else {
                dir = (dir + 1) % 4;
            }
            minR = min(minR, r);
            maxR = max(maxR, r);
            minC = min(minC, c);
            maxC = max(maxC, c);
        }
        if (minR == maxR || minC == maxC) {
            cout << 0 << "\n";
        } else {
            cout << (maxR - minR) * (maxC - minC) << "\n";
        }
    }

    return 0;
}