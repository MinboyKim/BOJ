#include <bits/stdc++.h>

using namespace std;

string arr[101];
int counts[101];

void init() {
    for (int i = 0; i < 101; i++) {
        counts[i] = 1;
    }
}

int main() {
    int n, a;
    string str;
    int cnt=1;
    while (true) {
        init();
        cin >> n;
        if (n == 0) {
            break;
        }

        cin.ignore();
        for (int i = 1; i <= n; i++) {
            getline(cin, arr[i]);
        }

        for (int i = 1; i <= 2 * n - 1; i++) {
            cin >> a;
            cin >> str;
            counts[a] *= -1;
        }
        for (int i = 1; i <= n; i++) {
            if (counts[i] == -1) {
                cout << cnt<<" "<<arr[i]<<'\n';
                break;
            }
        }
        cnt++;
    }
}