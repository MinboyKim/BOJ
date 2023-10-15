#include <bits/stdc++.h>

using namespace std;

int egg[1010];
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>egg[i];
    }

    sort(egg,egg+m);

    for(int i=0; i<m; i++){
        egg[i]=egg[i]*(m-i);
    }

    long long MAX=0;
    int idx;
    for(int i=1; (i<=n) && (i<m); i++){
        if(egg[m-i]>MAX) {
            MAX=egg[m-i];
            idx=egg[m-i]/i;
        }
    }
    cout<<idx<<" "<<MAX;

}