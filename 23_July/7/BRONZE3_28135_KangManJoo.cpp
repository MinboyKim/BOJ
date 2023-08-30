#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,cur=0;
    cin>>n;
    int cnt=0;
    while(true){
        cnt++;
        cur++;
        if (cur == n) break;
        string str=to_string(cur);
        if(str.find("50")!=string::npos)
            cnt++;
        
    }
    cout<<cnt;
}