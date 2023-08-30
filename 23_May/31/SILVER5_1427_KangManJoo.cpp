#include <bits/stdc++.h>

using namespace std;

int main(){
    char a[20];
    string n;
    cin>>n;
    int t=0;
    for(auto i:n){
        a[t]=i;
        t++;
    }
    sort(a,a+t,greater<int>());
    for(int i=0;i<t;i++){
        cout<<a[i];
    }
}