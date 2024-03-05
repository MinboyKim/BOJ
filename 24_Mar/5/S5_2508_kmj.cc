#include <iostream>
#include <string>

using namespace std;

int cnt;
int main() {
    int t, r, c;
    string space, candys[404], str;
    cin >> t;

    while (true) {
        cnt = 0;
        t--;
        if (t < 0) {
            break;
        }
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            cin >> str;
            candys[i] = str;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (candys[i][j] == '>') {
                    if (j < c - 2) {
                        if (candys[i][j + 1] == 'o') {
                            if (candys[i][j + 2] == '<') {
                                cnt++;
                            }
                        }
                    }
                }
                if (candys[i][j] == 'v') {
                    if (i < r - 2) {
                        if (candys[i + 1][j] == 'o') {
                            if (candys[i + 2][j] == '^') {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt<<'\n';
    }
}