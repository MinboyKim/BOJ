#include <bits/stdc++.h>

using namespace std;

int t;
stack<int> stk;
string q;
int i;

void solve(){
    int plag=1;
    i=0;
    for(auto& cur: q){
        if(cur=='('){
            i++;
        }
        else if(cur==')'){
            if(i<=0){
                plag=0;
                break;
            }
            i--;
        }
    }
    if(i!=0) plag=0;
    if(plag) cout<<"YES";
    else cout<<"NO";
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>q;
        solve();
    }
  
}