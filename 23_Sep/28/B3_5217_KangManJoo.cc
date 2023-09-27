#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t,a,b;
    cin>>n;
    while(n--){
        cin>>t;
        cout<<"Pairs for "<<t<<": ";
        int cnt=0;
        while(true){
            cnt++;
            if(cnt>=t-cnt) break;
            if(cnt>1) cout<<", ";
            cout<<cnt<<" "<<t-cnt;
        }
        cout<<"\n";
    }
}