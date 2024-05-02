#include <bits/stdc++.h>

using namespace std;

int n, c;
int main() {
    int arr[31];
    int total=0;
    cin >> n >> c;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
        total += arr[i];
    }

    int div = c / total;
    for (int i = 0; i < n; i++) {
        cout << div * arr[i] << '\n';
    }
}