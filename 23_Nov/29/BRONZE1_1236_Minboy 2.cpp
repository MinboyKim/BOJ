#include <iostream>
#include <string>

using namespace std;

int N, M, row, col;

char Arr[55][55];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++)
            Arr[i][j] = s[j];
    }

    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = 0; j < M; j++) {
            if (Arr[i][j] == 'X') {
                flag = true;
                break;
            }
        }
        if (!flag) row++;
    }

    for (int j = 0; j < M; j++) {
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (Arr[i][j] == 'X') {
                flag = true;
                break;
            }
        }
        if (!flag) col++;
    }

    cout << max(row, col) << "\n";

    return 0;
}