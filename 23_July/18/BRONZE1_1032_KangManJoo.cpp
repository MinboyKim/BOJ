#include<bits/stdc++.h>

using namespace std;

int main(){
    string s,tmp;
    int n;
    cin>>n;
    n--;
    cin>>s;
    while(n--){
        cin>>tmp;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=tmp[i]){
                s[i]='?';
            }
        }
    }
    cout<<s;
}