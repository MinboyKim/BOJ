#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,cnt;
int arr[100'001];
vector<int> segTree[400404];



void initSeg(int node, int left, int right){
    vector<int> v;
    for(int i=left; i<=right; i++){
        v.push_back(arr[i]);
    }
    //sort(v.begin(), v.end());
    for(auto &i: v){
        segTree[node].push_back(i);
    }
    if(left==right) return;
    initSeg(node*2, left, (left+right)/2);
    initSeg(node*2+1, (left+right)/2+1, right);

    return;
}

void findMST(int node, int left, int right, int start, int end, std::vector<int>& ans){
    if(left>end || right<start) return;

    if(start<=left && right<=end){
        ans.insert(ans.end(), segTree[node].begin(), segTree[node].end());
    }
    else{
        findMST(node*2, left, (left+right)/2, start, end,ans);
        findMST(node*2+1, (left+right)/2+1, right, start, end,ans);
    }
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    initSeg(1,1,n);
    
    int i,j,k;
    while(m--){
        cin>>i>>j>>k;
        vector<int> ans;
        findMST(1,1,n,i,j,ans);
        sort(ans.begin(),ans.end());
        cout<<ans[k-1]<<'\n';
    }
    

    return 0;
}
