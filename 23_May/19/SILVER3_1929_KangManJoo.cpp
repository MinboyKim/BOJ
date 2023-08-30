#include <bits/stdc++.h>

using namespace std;

int n,m;
int isNotPrime[1010100];


void primeNumber(){
    for(int i=2; i<1010100; i++){
        if(isNotPrime[i]) continue;
        for(int j=i*2; j<1010100; j+=i){
            if(isNotPrime[i]) continue;
            isNotPrime[j]=1;
        }
    }
    return;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n>>m;
    primeNumber();
    isNotPrime[1]=1;
    for(int i=n; i<=m; i++){
        if(!isNotPrime[i]) cout<<i<<'\n';
    }
}