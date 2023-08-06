#include <bits/stdc++.h>

using namespace std;



int main(){
    int n,result;
    cin>>n;

    int s = 1;
    for(int i=1; i<n; i++){
        s*=10;
    }
    
    for(int i=s; i<s*10; i++){
        string str = to_string(i);
        int t=0;
        bool usable=true;
        for(auto j : str){
            if(j>50){
                usable=false;
                break;
            }
            t+=j-48;
        }
        if (!usable) continue;
        if(t%3==0){
            result++;
        }
    }
    cout<<result;
}