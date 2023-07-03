#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,minSix=9999,minOne=9999;
    cin>>n>>m;
    int six,one;
    while(m--){
        cin>>six>>one;
        if(six<minSix) minSix=six;
        if(one<minOne) minOne=one;

    }
    if(minSix>minOne*6) minSix=minOne*6;
    int s,o;
    s=n/6;
    o=n%6;
    if(minSix<o*minOne){
        cout<<(s+1)*minSix;    
    }
    else cout<<s*minSix+o*minOne;
}