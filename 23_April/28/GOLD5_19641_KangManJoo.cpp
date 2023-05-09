#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<int> node[100'001];
pair<int,int> nodeRange[100'001];
int visited[100'001];

int dfs(int cur,int x){
    visited[cur]=1;
    nodeRange[cur].first=x;
    int outPut=x;
    sort(node[cur].begin(),node[cur].end());   //번호가 작은 자식노드부터 방문
    for(int i=0; i<node[cur].size(); i++){
        if(!visited[node[cur][i]])
            outPut=dfs(node[cur][i],outPut+1);
    }
    outPut++;
    nodeRange[cur].second=outPut;
    return outPut;
}

int main(){
    cin>>n;
    int nodeN,nNode;
    for(int i=0; i<n; i++){
        cin>>nodeN;      //node Number
        while(true){
            cin>>nNode;  //next Node;
            if(nNode==-1) break;
            node[nodeN].push_back(nNode);
            node[nNode].push_back(nodeN); //indirect
        }
    }
    cin>>q;
    dfs(q,1);

    for(int i=1; i<=n; i++){
        cout<<i<<" "<<nodeRange[i].first<<" "<<nodeRange[i].second<<'\n';
    }
}