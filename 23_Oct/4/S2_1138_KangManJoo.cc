#include <bits/stdc++.h>

using namespace std;

int arr[11];
int loc[11];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int curLoc = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (curLoc == cnt && !loc[j]) {
                loc[j] = i;
                break;
            }
            if (!loc[j])
                cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << loc[i] << " ";
    }
}