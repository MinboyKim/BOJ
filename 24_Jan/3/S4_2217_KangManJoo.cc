#include <bits/stdc++.h>

using namespace std;

int arr[101010];

int main() {
    int n, cost;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int Max = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int maxWeight = arr[i] * (n - i);
        if (Max < maxWeight)
            Max = maxWeight;
    }
    cout << Max;
}