#include <bits/stdc++.h>

using namespace std;

int a,b,c,d;
int main(){
    int t,cost;
    cin>>t;
    while(t--){
        cin>>cost;
        a=cost/25;
        cost%=25;
        b = cost / 10;
        cost %= 10;
        c = cost / 5;
        cost %= 5;
        d = cost;

        cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
    }
}