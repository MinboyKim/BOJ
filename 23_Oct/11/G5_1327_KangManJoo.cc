#include <bits/stdc++.h>

using namespace std;

int n,m,a,b;
int user[101];
vector<int> edge[101];
int MIN=INT_MAX;
int kv[101];
queue<pair<int,int>> q;
int checked[101];

int find_all(int x){
    q.push({x,0});
    int result =0;
    while(!q.empty()){
        pair<int,int> next=q.front();
        q.pop();
        if(checked[next.first]) continue;
        checked[next.first]=1;
        result+=next.second;
        for(auto i : edge[next.first]){
            if(!checked[i]){
                q.push({i,next.second+1});
            }
        }
    }
    return result;
}

void init(){
    for(int i=1; i<=n; i++){
        checked[i]=0;
    }
}

int main(){
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        init();
        kv[i]=find_all(i);
        if(MIN>kv[i]) MIN=kv[i];
    }

    for(int i=1; i<=n; i++){
        if(kv[i]==MIN) {
            cout<<i;
            break;
        }
    }
    return 0;
}