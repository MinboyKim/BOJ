#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,f;
    cin>>n>>f;
    n= (n/100) * 100;
    while(true){
        if(n%f==0) break;
        else n++;
    }
    if(n%100<10) cout<<"0"<<n%100;
    else cout<<n%100;
}