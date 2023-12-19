#include <bits/stdc++.h>

using namespace std;

int n;
long long pii[5][5];
pair<int, int> maxPii;
long long MAX;
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n;
    int arr[5];
    while (n--) {
        for (int i = 0; i < 5; i++) {
            cin >> arr[i];
        }
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                if (arr[j] && arr[k]) {
                    pii[j][k]++;
                    if (pii[j][k] > MAX) {
                        MAX = pii[j][k];
                        maxPii.first = j;
                        maxPii.second = k;
                    }
                }
            }
        }
    }
    cout << MAX << '\n';
    if (!MAX) {
        cout << "0 0 0 1 1";
    } else {
        for (int i = 0; i < 5; i++) {
            if (maxPii.first == i || maxPii.second == i) {
                cout << "1";
            } else
                cout << "0";
            cout << " ";
        }
    }
}