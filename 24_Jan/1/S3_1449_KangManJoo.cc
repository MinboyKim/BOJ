#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int main() {
    int n, l, loc;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> loc;
        arr.push_back(loc);
    }
    sort(arr.begin(), arr.end());

    int cover = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cover < arr[i]) {
            cover = arr[i] + l - 1;
            cnt++;
        }
    }
    cout << cnt;
}