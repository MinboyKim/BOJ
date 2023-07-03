#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,cnt;
int arr[100'001];
vector<int> segTree[400404];

int binary_search(int node,int left, int right, int val){
    int mid= (left+right)/2;
    if(left>right) return left;
    else if(segTree[node][mid]>val){
        right=mid-1;
        return binary_search(node,left,right,val);
    }
    else{
        left=mid+1;
        return binary_search(node,left,right,val);
    }
}

void initSeg(int node, int left, int right){
    vector<int> v;
    for(int i=left; i<=right; i++){
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for(auto &i: v){
        segTree[node].push_back(i);
    }
    if(left==right) return;
    initSeg(node*2, left, (left+right)/2);
    initSeg(node*2+1, (left+right)/2+1, right);

    return;
}

void findMST(int node, int left, int right, int start, int end, int k){
    if(left>end || right<start) return;

    if(start<=left && right<=end){
        int size=segTree[node].size();
        int idx=binary_search(node,0,size-1,k); //idx를 포함한 그 이후의 것들이 k보다 크다.
        cnt+=size-idx;
    }
    else{
        findMST(node*2, left, (left+right)/2, start, end, k);
        findMST(node*2+1, (left+right)/2+1, right, start, end, k);
    }
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    initSeg(1,1,n);
    cin>>m;
    
    int i,j,k;
    while(m--){
        cnt=0;
        cin>>i>>j>>k;
        findMST(1,1,n,i,j,k);
        cout<<cnt<<'\n';
    }

    return 0;
}
