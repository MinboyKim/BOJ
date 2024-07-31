#include <bits/stdc++.h>

using namespace std;

long long arr[100001];

int main(){
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cnt = 0;

    for (int i = 0; i < n-1; i++){
        if(arr[i]<arr[i+1]){
            continue;
        }
        else{
            arr[i + 1] += m;
            if(arr[i]>=arr[i+1]){
                cout << "-1";
                return 0;
            }
            cnt++;
        }
    }
    cout << cnt;
}