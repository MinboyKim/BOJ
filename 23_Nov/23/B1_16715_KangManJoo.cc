#include <bits/stdc++.h>

using namespace std;
int n;  
long long MAX;
int idx;

void solve(int i){
    int quot=n, denom,sum=0;
    while(quot){
        denom=quot%i;
        quot=quot/i;
        sum+=denom;
    }
    if(MAX<sum){
        MAX=sum;
        idx=i;
    }
}

int main(){
    cin>>n;
    for(int i=2; i<=n; i++){
        solve(i);
    }

    cout<<MAX<<" "<<idx;
}