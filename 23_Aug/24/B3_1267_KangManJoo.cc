#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
    cin>>n;
    int y=0,m=0;
    int cost;
    while(n--){
        cin>>cost;
        y+=(cost/30)*10;
        m+=(cost/60)*15;
        y+=10;
        m+=15;
    }
    if(y>m){
        cout<<"M "<<m;
    }
    else if(y<m){
        cout<<"Y "<<y;
    }
    else{
        cout<<"Y M "<<y;
    }
}