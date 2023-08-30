#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d,e,tmp1,tmp2;
    cin>>a>>b>>c>>d>>e;
    if(a>b){
        tmp1=b;
    }
    else {
        tmp1=a;
    }
    if(tmp1>c){
        tmp1=c;
    }
    
    if(d>e){
        tmp2=e;
    }
    else tmp2=d;
    
    cout<<tmp1+tmp2-50;
}