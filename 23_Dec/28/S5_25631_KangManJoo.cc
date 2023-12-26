#include <bits/stdc++.h>

using namespace std;

int arr[1010];
int matro[1010];
int maxNum;
int sum=0;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    int cur=arr[0];
    int idx=0;
    for(int i=0; i<n; i++){
        if(cur==arr[i]){
            matro[idx]++;
        }
        else{
            cur=arr[i];
            idx++;
            matro[idx]++;
        }
    }

    for(int i=0; i<=idx; i++){
        if(matro[i]-maxNum>0){
            sum+=matro[i]-maxNum;
        }
        if(maxNum<matro[i]) maxNum=matro[i];
    }

    cout<<sum;


    
}