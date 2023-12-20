#include <bits/stdc++.h>

using namespace std;

int n;
int len;
int arr[40004];
int lis[40004];

int binarySearch(int x){
    int left =1;
    int right=len;
    int mid;

    while(left<right){
        mid=(left+right)/2;
        if(lis[mid]<x){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }

    return right;
}

int main(){
    cin>> n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        if(lis[len]<arr[i]){
            len++;
            lis[len] = arr[i];
        }
        else{
            int idx= binarySearch(arr[i]);
            lis[idx] = arr[i];
        }
    }

    cout<<len;
}