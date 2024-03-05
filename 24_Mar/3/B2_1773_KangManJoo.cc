#include <bits/stdc++.h>

using namespace std;

int arr[2000001];

int main() {
    int a, b, c;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> c;
        for (int j = c; j <= b; j += c) {
            arr[j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= b; i++) {
        if (arr[i])
            cnt++;
    }
    cout << cnt;
}