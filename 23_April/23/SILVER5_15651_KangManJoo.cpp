#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
pii arr[100'001];

bool manjoo(pii a, pii b){ 
    if(a.second==b.second){
        return a.first<b.first;
    }
    else return a.second<b.second; 
} 

int main(){
    int n,x,y;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n,manjoo);
    for(int i=0; i<n; i++) cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    return 0;
}