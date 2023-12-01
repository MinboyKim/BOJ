#include <bits/stdc++.h>

using namespace std;

string str;
char c, preC, startC;
int n, preN, startN;
int board[6][6];
int main() {
    cin >> str;
    preC = str[0] - 65;
    preN = str[1]-49;
    int valid = 1;
    int cnt = 35;

    board[preC][preN] = 1;

    while (cnt--) {
        cin >> str;
        c = str[0] - 65;
        n = str[1]-49;
        board[c][n] = 1;
        if (abs(preC-c) == 1) {
            if (abs(preN - n) != 2) {
                valid = 0;
            }

        } else if (abs(preC - c) == 2) {
            if (abs(preN - n) != 1) {
                valid = 0;
            }
        } else {
            valid = 0;
        }
        preC = c;
        preN = n;
    }

    if (abs(preC - startC) == 1) {
        if (abs(preN - startN) != 2) {
            valid = 0;
        }

    } else if (abs(preC - startC) == 2) {
        if (abs(preN - startN) != 1) {
            valid = 0;
        }
    } else {
        valid = 0;
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (!board[i][j]) {
                valid = 0;
            }
        }
    }

    if (valid) {
        cout << "Valid";
    } else
        cout << "Invalid";
}