#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll accumSum[101010];
int n,credit,sale,cnt;
ll prices[101010];
int main(){
    cin>>n>>credit>>sale;
    for(int i=0; i<n; i++){
        cin>>prices[i];

    }
    sort(prices,prices+n);
    for(int i=0; i<n; i++){
        cnt++;
        if(i==0)accumSum[i]=prices[i]/2;
        else accumSum[i]=accumSum[i-1]+prices[i]/2;
        if(cnt>sale){
            accumSum[i]+=prices[i-sale]/2;
        }
        if(accumSum[i]>credit) {
            cout<<i; 
            return 0;
        }
    }
    cout<<n;
    return 0;



}