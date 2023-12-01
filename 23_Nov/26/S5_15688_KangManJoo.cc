#include <bits/stdc++.h>

using namespace std;

int arr[1000100];
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<'\n';
    }
}