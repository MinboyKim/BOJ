#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int n,m;
vector<int> v[33000];
int degree[33000];
vector<int> answer;
int main(){
    cin>>n>>m;
    int Pnode,Nnode;
    while(m--){
        cin>>Pnode>>Nnode;
        v[Pnode].push_back(Nnode);
        degree[Nnode]++;
    }

    for(int i=1; i<=n; i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        answer.push_back(cur);

        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i];
            degree[next]--;
            if(!degree[next]){
                q.push(next);
            }

        }
    }
    for(auto& i:answer) cout<<i<<" ";
}