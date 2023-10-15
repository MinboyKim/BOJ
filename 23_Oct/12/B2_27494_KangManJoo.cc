#include <bits/stdc++.h>

using namespace std;

int sum;
char year[4]={'2','0','2','3'};

void check(int x){
    string s=to_string(x);
    int flag=0;
    for(auto i:s){
        if(i==year[flag]){
            flag++;
        }
        if(flag==4){
            sum++;
            break;
        }
    }
}
int main(){
    int n;
    cin>> n;
    for(int i=2023; i<=n; i++){
        check(i);
    }
    cout<<sum;
}