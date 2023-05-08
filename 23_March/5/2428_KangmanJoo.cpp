#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100100];
long long sum;

void bs(int cur,int left,int right){
    int mid=(left+right)/2;
    double similarity=arr[mid]*0.9;

    if(left>=right){
        if(arr[cur]<similarity) right--;
        sum+=right-cur;
        return;
    }

    if(arr[cur]>=similarity) bs(cur,mid+1,right);
    else bs(cur,left,mid);
    
    return;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for(int i=0; i<n-1; i++) bs(i,i+1,n-1);

    cout<<sum;
}