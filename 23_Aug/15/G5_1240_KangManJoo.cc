#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
vector<pii> Node[1010];
int visited[1010];
int n,m;


void dfs(int cur, int dest, int dist){
    if(cur==dest){
        cout<<dist<<'\n';
        return;
    }
    visited[cur]=1;

    for(int i=0; i<Node[cur].size(); i++){
        if(!visited[Node[cur][i].first]){
            dfs(Node[cur][i].first,dest,dist+Node[cur][i].second);
        }
    }
}

void init(){
    for(int i=0; i<=n; i++){
        visited[i]=0;
    }
}

int main(){
    int a,b,dist;

    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>dist;
        Node[a].push_back({b,dist});
        Node[b].push_back({a, dist});
    }

    while(m--){
        cin>>a>>b;
        dfs(a,b,0);
        init();
    }
}