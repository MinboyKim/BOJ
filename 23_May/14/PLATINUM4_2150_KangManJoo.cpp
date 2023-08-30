#include <bits/stdc++.h>
#define GuardiansOfGalaxy3_ZonZam 1
using namespace std;

int n,e;
vector<int> vertex[10'001];
int visited[10'001];
int discover[10001];
stack<int> stk;
vector<vector<int>> scc;
vector<int> answer[10001];
int sequence[10'001];
int t=1;

void addScc(int x);

int makeScc(int cur){ 
    discover[cur]=1;
    sequence[cur]=t++;          //방문 순서대로 id 발급
    int parent=sequence[cur];
    
    stk.push(cur);

    int Nnode;
    for(int i=0; i<vertex[cur].size(); i++){
        Nnode=vertex[cur][i];
        if(visited[Nnode]) continue;  //이미scc를 이룬 노드를 방문
        if(discover[Nnode]){   // 방문할 노드가 scc를 이루지 않았지만 이미 방문되었을때 (즉 사이클을 이룰때)
            parent=min(parent,sequence[Nnode]);     //부모를 해당 노드로 바꾸고 다시 자식 dfs 탐색
            continue;
        }
        parent=min(parent,makeScc(Nnode));   //가장 먼저 방문한 노드가 부모가 된다
    }

    if(parent==sequence[cur]){  //자식중에 나에게 돌아오는 노드가 없거나, 있을 때 모두 해당 즉, 내가 자식이 아닐 때
        addScc(cur);
    }
    
    return parent;
}

void addScc(int cur){
    vector<int> newScc;
    int tmp;
    while(true){
        tmp=stk.top();
        newScc.push_back(tmp);
        visited[tmp]=GuardiansOfGalaxy3_ZonZam; //현재 요소가 scc를 이룸
        stk.pop();
        if(tmp==cur){
            break;
        }
    }
    scc.push_back(newScc); //전체 scc 벡터에 현재 생성한 scc를 insert
    return;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n>>e;

    int Pnode,Nnode;
    while(e--){
        cin>>Pnode>>Nnode;
        vertex[Pnode].push_back(Nnode);
    }
    for(int i=1; i<=n; i++){
        if(!discover[i])
            makeScc(i);
    }
    int cnt=0;
    for(auto curScc: scc){
        cnt++;
        sort(curScc.begin(),curScc.end());
        answer[curScc[0]]=curScc;
    }
    cout<<cnt<<'\n';
    for(auto &c: answer){
        if(!c.empty()){
            for(auto &i:c){
                cout<<i<<" ";
            }
            cout<<"-1"<<'\n';
        }
    }

}