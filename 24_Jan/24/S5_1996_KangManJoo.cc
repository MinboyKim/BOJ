#include <bits/stdc++.h>

using namespace std;

char arr[1010][1010];
char arr2[1010][1010];
string str;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= str.length(); j++) {
            arr[i][j] = str[j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != '.') {
                arr2[i][j] = '*';
            } else {
                int sum = 0;
                for (int k = 0; k < 8; k++) {
                    if (arr[i + dx[k]][j + dy[k]] != '.' &&
                        arr[i + dx[k]][j + dy[k]] != 0) {
                        sum += arr[i + dx[k]][j + dy[k]] - '0';
                    }
                }
                arr2[i][j] = sum+'0';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(arr2[i][j]>'9'){
                cout << 'M';
            }
            else cout << arr2[i][j];
        }
        cout << '\n';
    }
}