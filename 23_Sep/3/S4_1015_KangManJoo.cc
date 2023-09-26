#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    pair<int, int> arr[1001];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);

    int answer[1001];

    for (int i = 0; i < n; i++) {
        answer[arr[i].second] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
}