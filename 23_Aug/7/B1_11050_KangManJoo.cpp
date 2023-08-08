#include <bits/stdc++.h>

using namespace std;

int n,k;
int facto[10001000];

int factorial(int x){
    if(x==1) return 1;

    if(facto[x]) return facto[x];
    else{
        facto[x]=x*factorial(x-1);
        return facto[x];
    }
}

int main(){
    cin>>n>>k;
    factorial(n);
    facto[0]=1;
    facto[1]=1;
    cout<< facto[n] / (facto[n - k] * facto[k]);
}