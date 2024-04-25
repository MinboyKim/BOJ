#include <bits/stdc++.h>

using namespace std;

int arr[303][303];
int main() {
    int n, m,k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> k;
    int ax, ay, bx, by;
    while (k--) {
        int sum = 0;
        cin >> ax >> ay >> bx >> by;
        for (int i = ax; i <= bx; i++){
            for (int j = ay; j <= by; j++){
                sum += arr[i][j];
            }
        }
        cout << sum << '\n';
    }
}