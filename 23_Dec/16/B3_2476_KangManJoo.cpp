#include <bits/stdc++.h>

using namespace std;

int sum,a,b,c;
int MAX;
set<int> s;
int main(){
    int t;
    cin>>t;
    while(t--){
        sum=0;
        cin>>a>>b>>c;
        if(a==b && b==c){
            sum+=10000+1000*a;
        }
        else if(a==b || a==c){
            sum+=1000+a*100;
        }
        else if(b==c){
            sum+=1000+b*100;
        }
        else{
            sum+=100*max(a,max(b,c));
        }
        if(MAX<sum) MAX=sum;
    }
    cout<<MAX;
}