#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int lv;
int ans;

int dx[4] = {0, 0, 1, 0};
int dy[4] = {0, 1, -1, 1};

void solve(int curSize, int row, int col) {
    if (curSize == 2) {
        for (int i = 0; i < 4; i++) {
            row += dx[i];
            col += dy[i];
            if (row == r && col == c) {
                cout << lv;
                exit(0);
            }
            lv++;
        }
        return;
    }

    int nSize = curSize / 2;
    if (r < row + nSize && c < col + nSize)
        solve(nSize, row, col);
    else if (r < row + nSize) {
        lv += pow(nSize, 2);
        solve(nSize, row, col + nSize);
    } else if (c < col + nSize) {
        lv += pow(nSize, 2) * 2;
        solve(nSize, row + nSize, col);
    } else {
        lv += pow(nSize, 2) * 3;
        solve(nSize, row + nSize, col + nSize);
    }
}

int main() {
    cin >> n >> r >> c;

    int size = pow(2, n);

    solve(size, 0, 0);
}