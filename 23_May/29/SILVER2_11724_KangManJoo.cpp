#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> edge[1001];
int checked[1001];
int cnt;

void dfs(int cur){
    checked[cur]=1;

    for(int i=0; i<edge[cur].size(); i++){
        if(!checked[edge[cur][i]]){
            dfs(edge[cur][i]);
        }
    }
}

int main(){
    cin>>n>>m;
    int pnode,nnode;
    while(m--){
        cin>>pnode>>nnode;
        edge[pnode].push_back(nnode);
        edge[nnode].push_back(pnode);
    }

    for(int i=1; i<=n; i++){
        if(!checked[i]){
            dfs(i);
            cnt++;
        }
    }

    cout<<cnt;
}