#include <bits/stdc++.h>

using namespace std;

int arr[10];
int digit[500];
int n,num;
int idx=1; //자릿수
int j;
int preNum;

void solve(){
    j++;
    digit[j]=digit[j-1]*10+idx;       //각 자릿수마다 각 수가 나오는 횟수 0은?

    for(auto&cur :arr)cur+=num*digit[j-1];
    for(int i=1; i<num; i++)arr[i]+=idx;
    arr[num]+=preNum;

}

int main(){
    cin>>n;
    while(n){
        num=n%10;
        n/=10;
        solve();
        preNum+=num*idx;
        idx*10;
    }

    for(auto &i: arr) cout<<i<<" ";
}