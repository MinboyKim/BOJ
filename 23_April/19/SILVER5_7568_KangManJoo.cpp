#include <bits/stdc++.h>

using namespace std;

int n,a,b;
int lv[55];
pair<int,int> pr[55];

int main(){
    cin>>n; 
    fill_n(lv, n, 1);  //init
    for(int i=0; i<n; i++) cin>>pr[i].first>>pr[i].second;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(pr[i].first<pr[j].first && pr[i].second<pr[j].second) lv[i]++;
        
    for(int i=0; i<n; i++) cout<<lv[i]<<" ";
    return 0;
}
