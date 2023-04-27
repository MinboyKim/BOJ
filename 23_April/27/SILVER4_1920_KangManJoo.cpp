#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    map<int,int> mapp;
    int n,m,val;
    cin>>n;
    while(n--){
        cin>>val;
        mapp.insert({val,1});
    }
    cin>>m;
    while(m--){
        cin>>val;
        if(mapp.find(val)!=mapp.end()) cout<<"1"<<'\n';   
        else  cout<<"0"<<'\n';
         
    }
    
}