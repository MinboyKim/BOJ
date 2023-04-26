#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int n,m,k;
ll segTree[4'040'004];
ll lazy[4'040'004];
ll arr[1'010'001];

void initSegTree(int node, int start, int end){
    if(start==end){    //leafNode;
        segTree[node]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    initSegTree(node*2,start, mid);
    initSegTree(node*2+1,mid+1, end);
    segTree[node]=segTree[node*2]+segTree[node*2+1];
    return;
}

void updateLazy(int node,int left, int right){
    if(lazy[node]==0) return;

    ll updateCost=lazy[node]*((ll)right-left+1); //long long type casting
    segTree[node]+=updateCost;
    if(left!=right){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;

    return;
}

void updateTree(int node,int left,int right,int start,int end,ll sumI){ //left,right=> node's range start,end=>find range
    updateLazy(node, left, right); 
    if(left>end || right<start) return;  //out of range

    if(start<=left && right<=end){      //whole num in range
        segTree[node]+=sumI*((ll)right-left+1);
        if(left!=right){  //not leaf
            lazy[node*2]+=sumI;
            lazy[node*2+1]+=sumI;
        }
        return;
    }

    int mid=(left+right)/2;
    updateTree(node*2,left,mid,start,end,sumI);
    updateTree(node*2+1,mid+1,right,start,end,sumI);
    segTree[node]=segTree[node * 2] + segTree[node * 2 + 1];
    return;
}

ll findSum(int node,int left,int right,int start,int end){
    updateLazy(node,left,right);

    if(left>end || right<start) return 0;  //out of range


    if(start<=left && right<=end){      //whole num in range
        return segTree[node];
    }
     int mid=(left+right)/2;
    return findSum(node*2,left,mid,start,end)+findSum(node*2+1,mid+1,right,start,end);
    
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    ll val;
    for(int i=1; i<=n; i++) cin>>arr[i];
    initSegTree(1,1,n);
    int query=m+k,q,a,b,sumI;
    while(query--){
        cin>>q>>a>>b;
        if(q==1){
            cin>>sumI;
            updateTree(1,1,n,a,b,sumI);
        }
        else if(q==2) {
           cout<<findSum(1,1,n,a,b)<<'\n';
        }
    }

    return 0;
}
