#include <bits/stdc++.h>

using namespace std;

int n,num;
typedef pair<int,int> pii;
pii meet[101010];
int curTime;

bool cmp(pii a, pii b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>meet[i].first>>meet[i].second;
    }

    sort(meet,meet+n,cmp);
    int curLoc=0;
    while(true){
        int i;
        for(i=curLoc; i<n;i++){
                if(meet[i].first>=curTime){
                    curLoc=i+1;
                    curTime=meet[i].second;
                    break;
                }
        }
        if(i>=n) break;
        num++;
    }
    cout<<num;
}
