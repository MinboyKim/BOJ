#include <bits/stdc++.h>

using namespace std;

int arr[1000000];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<arr[0]*arr[n-1];
}