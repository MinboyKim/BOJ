#include <bits/stdc++.h>
# define MAX 500'405

using namespace std;

typedef long long ll;

int n,m,q,a,b,x;
ll lazy[MAX];
vector<int> segTree[MAX];
int pay[MAX];
pair<int,int> range[MAX];
int virtualIndex[MAX];

int dfsSegTree(int cur,int inputN){
    range[cur].first=inputN;
    int outPutN=inputN,nextNode;
    for(int i=0; i<segTree[cur].size(); i++){
        nextNode=segTree[cur][i];
        outPutN=dfsSegTree(nextNode,++outPutN);
    }
    range[cur].second=outPutN;
    return outPutN;
}






int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin>>n>>q;
    int boss;
   
    char query;
    int idx,inc;
    while(q--){
        cin>>query>>idx;
        if(query=='p'){
            cin>>inc;
            updateSegTree(1,idx,inc);
        }
        else{
            findPay(1,idx);
        }
    }
    return 0;
}