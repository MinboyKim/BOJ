#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];
int main(){
    cin>>n;
    dp[1]=1;
    dp[3]=1;
    for(int i=4; i<=n; i++) if(!dp[i-1]||!dp[i-3]) dp[i]=1;
    if(dp[n]) cout<<"SK";
    else cout<<"CY";
    
    return 0;
}