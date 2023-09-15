#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    char a=s[0];
    for(auto i:s){
        if(a!=i) {
            cnt++;
            a=i;
        }
    }
    cout<<cnt/2+cnt%2;
}