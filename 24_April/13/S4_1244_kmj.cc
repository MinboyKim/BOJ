#include <bits/stdc++.h>

using namespace std;

int arr[101];

int swap(int x) {
    x *= -1;
    x++;
    return x;
}

int main() {
    int n, k, sex, loc;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> sex >> loc;
        if (sex == 1) {
            for (int j = loc; j <= n; j += loc) {
                arr[j] = swap(arr[j]);
            }
        } else {

            arr[loc] = swap(arr[loc]);
            int cnt = 1;
            while(loc-cnt>=1 && loc+cnt<=n){
                if(arr[loc-cnt]==arr[loc+cnt]){
                    arr[loc - cnt] = swap(arr[loc - cnt]);
                    arr[loc + cnt] = swap(arr[loc + cnt]);
                }
                else{
                    break;
                }
                cnt++;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
        if(i%20==0){
            cout << '\n';
        }
    }
}