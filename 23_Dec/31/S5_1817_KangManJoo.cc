#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int main(){
    int n,m,cost;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>cost;
        arr.push_back(cost);
    }
    
    int cur=0,cnt=1;
    for(int i=0; i<n; i++){
        cost=arr[i];
        if(cur+cost >m){
            cur=0;
            cnt++;
        }
        cur+=cost;
    }
    if(n==0) cout<<0;
    else cout<<cnt;
}