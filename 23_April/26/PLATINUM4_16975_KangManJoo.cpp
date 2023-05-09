#include <bits/stdc++.h>
# define MAX 400'404

using namespace std;

typedef long long ll;

int n,m,q,a,b,x;
ll val;
ll segTree[MAX];
ll lazy[MAX];

void initSegTree(int idx,int node,int start,int end,ll val){
    if(idx<start||idx>end) return;
    if(start<=idx&&idx<=end) {
        segTree[node]+=val;
        if(start==end) return;
    }
    int mid=(start+end)/2;
    initSegTree(idx,node*2,start,mid,val);
    initSegTree(idx,node*2+1,mid+1,end,val);
    return;
}

void updateLazy(int node,int start, int end){
    if(!lazy[node]) return;

    segTree[node]+=lazy[node]*((ll)end-start+1);
    if(start!=end){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
    return;
}

void updateSegTree(int node, int start, int end,int left, int right,ll val){
    updateLazy(node,start,end);
    if(right<start||left>end) return;
    if(left<=start&&end<=right){
        segTree[node]+=val*((ll)end-start+1);
        if(start!=end){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    updateSegTree(node*2,start,mid,left,right,val);
    updateSegTree(node*2+1,mid+1,end,left,right,val);
    segTree[node]=segTree[node*2]+segTree[node*2+1];
}

ll findIdx(int x){
    int start=1,end=n,curNode=1;
    while(start<=end){
        updateLazy(curNode,start,end);
        int mid=(start+end)/2;
        if(start==end) break;
        if(x>mid) {
            curNode=curNode*2+1;
            start=mid+1;
        }
        else{
            end=mid;
            curNode*=2;
        }
    }
    return segTree[curNode];
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin>>n;
    ll val;
    for(int i=1; i<=n; i++){
        cin>>val;
        initSegTree(i,1,1,n,val);
    }
    cin>>m;
    while(m--){
        cin>>q;
        if(q==1){
            cin>>a>>b>>val;
            updateSegTree(1,1,n,a,b,val);
        }
        else{
            cin>>x;
            cout<<findIdx(x)<<'\n';
        }
    }
    return 0;
}