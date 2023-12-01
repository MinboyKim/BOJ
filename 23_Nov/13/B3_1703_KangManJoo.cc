#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, cnt,b,c;
    while(1){
        cnt=1;
        cin>>a;
        if(a==0){
            break;
        }
        while(a--){
            cin>>b>>c;
            cnt=cnt*b-c;
        }
        cout<<cnt<<'\n';
    }
}