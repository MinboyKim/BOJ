#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        for(auto &i:s){
            i=tolower(i);
            cout<<i;
        }
        cout<<'\n';
    }
}