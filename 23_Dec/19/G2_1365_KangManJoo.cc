#include <bits/stdc++.h>

using namespace std;

int arr[100100];
int lis[100100];
int len = 0;
int n, loc;

int binaryS(int x) {
    int left = 1;
    int right = len;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return right;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> loc;
        arr[i] = loc;
    }

    for (int i = 1; i <= n; i++) {
        if (lis[len] < arr[i]) {
            len++;
            lis[len] = arr[i];
        } else {
            int idx = binaryS(arr[i]);
            lis[idx] = arr[i];
        }
    }

    cout << n - len;
}