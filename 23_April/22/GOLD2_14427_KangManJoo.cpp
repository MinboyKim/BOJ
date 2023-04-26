#include <bits/stdc++.h>

using namespace std;

int n,m,cost;
pair<int,int> arrTree[400'404];

void initTree(int cost,int curIdx){
    int i=1;
    int left=1; int right= n;
    int treeIdx=1;
    int mid;

     if(arrTree[treeIdx].second==0||(arrTree[treeIdx].first>cost)){  //when treeIdx=1;
            arrTree[treeIdx].first=cost;
            arrTree[treeIdx].second=curIdx;
        }
        else if(arrTree[treeIdx].first==cost){
            if(arrTree[treeIdx].second>curIdx){
                arrTree[treeIdx].first=cost;
                arrTree[treeIdx].second=curIdx;
            }
    }

    while(left<right){
        mid=(right+left)/2;
        if(curIdx>mid){
            left=mid+1;
            treeIdx=treeIdx*2+1;
        }
        if(curIdx<=mid){
            right=mid;
            treeIdx*=2;
        }
        if(arrTree[treeIdx].second==0||(arrTree[treeIdx].first>cost)){  //first init or update minCost
            arrTree[treeIdx].first=cost;
            arrTree[treeIdx].second=curIdx;
        }
        else if(arrTree[treeIdx].first==cost){
            if(arrTree[treeIdx].second>curIdx){
                arrTree[treeIdx].first=cost;
                arrTree[treeIdx].second=curIdx;
            }
        }
    }
    return;
}

void change(int curIdx, int newCost){
    int treeIdx=1,mid,left=1,right=n;
    while(left<right){
        mid=(right+left)/2;
        if(curIdx>mid){
            left=mid+1;
            treeIdx=treeIdx*2+1;
        }
        if(curIdx<=mid){
            right=mid;
            treeIdx*=2;
        }
    }
    arrTree[treeIdx].first=newCost;
    while(treeIdx){
        treeIdx/=2;
        if(arrTree[treeIdx*2].first>arrTree[treeIdx*2+1].first){
            arrTree[treeIdx].first=arrTree[treeIdx*2+1].first;
            arrTree[treeIdx].second=arrTree[treeIdx*2+1].second;
        }
        else{
             arrTree[treeIdx].first=arrTree[treeIdx*2].first;
            arrTree[treeIdx].second=arrTree[treeIdx*2].second;
        }
    }
}

void solve(){
    cout<<arrTree[1].second<<'\n';
    return;
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio;
    fill(arrTree,arrTree+200002,pair<int,int>(0,0));  //pii init
    
    cin>>n;

    for(int idx=1; idx<=n; idx++) {
        cin>>cost;
        initTree(cost,idx);
    }
    cin>>m;
    int q,a,b;


    while(m--){
        cin>>q;
        if(q==1) {
            cin>>a>>b;
            change(a,b);
        }
        else solve();
    }
    return 0;
}