#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);

    int n;
    int arr[303030];
    int flag=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        if(i%2==0){
            if(arr[i]%2!=0) flag=0;
        }
        if(i%2==1){
            if(arr[i]%2!=1) flag=0;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
}