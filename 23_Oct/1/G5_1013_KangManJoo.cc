#include <bits/stdc++.h>
#include <regex>

using namespace std;

//(100+1+ | 01)+
string s;

bool solve(){
    regex pattern("(100+1+|01)+");
    return regex_match(s,pattern);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        if(solve()) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
}