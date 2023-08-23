#include <bits/stdc++.h>

using namespace std;

vector<int> edge[100100];
int parent[100100];
int visited[100100];

void dfs(int cur, int parentNode){
    parent[cur]=parentNode;
    visited[cur]=1;

    for(int i=0; i<edge[cur].size(); i++){
        if(!visited[edge[cur][i]]){
            dfs(edge[cur][i],cur);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int Pnode,Nnode;
    for(int i=0; i<n-1; i++){
        cin>>Pnode>>Nnode;
        edge[Pnode].push_back(Nnode);
        edge[Nnode].push_back(Pnode);
    }

    dfs(1,0);

    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
}