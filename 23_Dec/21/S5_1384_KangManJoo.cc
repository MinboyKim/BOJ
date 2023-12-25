#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int n;
    string s;
    char c;
    int num = 1;
    while (true) {

        string namelist[42];
        int arr[40][40];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j]=0;
            }
        }
        cin >> n;
        if (n == 0)
            break;
        if (num != 1) {
            cout << '\n';
        }
        cout << "Group " << num << '\n';
        for (int i = 0; i < n; i++) {
            cin >> s;
            namelist[i] = s;
            namelist[i + n] = s;
            for (int j = n - 2; j >= 0; j--) {
                cin >> c;
                if (c == 'P') {
                    arr[i][(i + j + 1) % n] = 0;
                } else {
                    arr[i][(i + j + 1) % n] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >= 0; j--) {
                if (arr[i][(i+j+1)%n] == 1) {
                    cnt++;
                    cout << namelist[(i + j + 1) % n] + " was nasty about " +
                                namelist[i]
                         << '\n';
                }
            }
        }
        if (cnt == 0) {
            cout << "Nobody was nasty" << '\n';
        }
        num++;
    }
}