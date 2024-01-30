#include <bits/stdc++.h>

using namespace std;

int arr[200];
long long cnt;
int main() {
    int n,cost;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> cost;
    for (int i = 0; i < n; i++){
        if(!arr[i])
            continue;
        else{
            cnt += arr[i] / cost;
            if(arr[i]%cost!=0){
                cnt++;
            }
        }
    }
    cout << cnt*cost;
}