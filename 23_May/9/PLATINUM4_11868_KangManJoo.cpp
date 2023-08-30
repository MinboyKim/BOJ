#include <bits/stdc++.h>

using namespace std;

int n,tmp;
int arr[101];
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        tmp=tmp^arr[i];
    }
    if(tmp) cout<<"koosaga";
    else cout<<"cubelover";
    return 0;
}