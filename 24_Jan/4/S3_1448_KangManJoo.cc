#include <bits/stdc++.h>

using namespace std;

int arr[1000100];
int main() {
    int n;
    int sum = -1;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<>());

    for (int i = 0; i < n-2; i++){
        if(arr[i]<arr[i+1]+arr[i+2]){
            sum = arr[i] + arr[i + 1] + arr[i + 2];
            break;
        }
    }
    cout << sum;
}