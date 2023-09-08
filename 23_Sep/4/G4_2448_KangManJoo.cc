#include <bits/stdc++.h>

using namespace std;

int n;
char board[8000][8000];

void fractal(int y, int x, int n) {
    if (n == 3) {
        board[y][x] = '*';
        board[y + 1][x - 1] = '*';
        board[y + 1][x + 1] = '*';
        for (int i = -2; i <= 2; i++) {
            board[y + 2][x + i] = '*';
        }
        return;
    }

    fractal(y, x, n / 2);
    fractal(y + n / 2, x - n / 2, n / 2);
    fractal(y + n / 2, x + n / 2, n / 2);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {
            board[i][j] = ' ';
        }
    }

    fractal(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}