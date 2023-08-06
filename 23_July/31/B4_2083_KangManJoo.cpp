#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n,m;
    
    while(true){
        cin>>s>>n>>m;
        if(s=="#" && !n && !m) break;
        else{
            if(n>17 || m>=80){
                cout<<s<<" Senior";
            }
            else{
                cout << s << " Junior";
            }
            cout<<'\n';
        }
    }
}