#include <bits/stdc++.h>

using namespace std;

long long arr[3][100100];
// 0 -> 없음
// 1 -> 왼쪽 존재
// 2 -> 오른쪽 존재

int main() {
    int n;
    cin >> n;

    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[2][0] = 1;

    for (int i = 1; i < n; i++) {
        arr[0][i] = (arr[1][i - 1] + arr[2][i - 1] + arr[0][i - 1]) % 9901;
        arr[1][i] = (arr[0][i - 1] + arr[2][i - 1]) % 9901;
        arr[2][i] = (arr[0][i - 1] + arr[1][i - 1]) % 9901;
    }
    long long answer = arr[0][n - 1] + arr[1][n - 1] + arr[2][n - 1];
    cout << answer % 9901;
}
