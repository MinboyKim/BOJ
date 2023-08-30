#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<int> vertex[20'002];
int visited[20002];
int discover[20002];
stack<int> stk;
vector<vector<int>> scc;
int sequence[20002];
int t=1;
int num;
int sccNum[20002];


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
    num++;
    int tmp;
    while(true){
        tmp=stk.top();
        sccNum[tmp]=num;
        visited[tmp]=1; //현재 요소가 scc를 이룸
        stk.pop();
        if(tmp==cur){
            break;
        }
    }
    
    return;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n>>e;

    int Pnode,Nnode;
    while(e--){
        cin>>Pnode>>Nnode;
        if(Pnode>0&&Nnode>0){
            vertex[Pnode+10000].push_back(Nnode);
            vertex[Nnode+10000].push_back(Pnode);
        }
        else if(Pnode<=0&&Nnode<=0){
            vertex[abs(Pnode)].push_back(abs(Nnode)+10000);
            vertex[abs(Nnode)].push_back(abs(Pnode)+10000);
        }
        else if(Pnode>0&&Nnode<=0){
            vertex[Pnode+10000].push_back(abs(Nnode)+10000);
            vertex[abs(Nnode)].push_back(Pnode);
        }
        else if(Pnode<=0&&Nnode>0){
            vertex[Nnode+10000].push_back(abs(Pnode)+10000);
            vertex[abs(Pnode)].push_back(Nnode);
        }
    }
    for(int i=1; i<=n; i++){
        if(!discover[i])
            makeScc(i);
    }

    for(int i=1; i<=n; i++){
        if(!discover[10000+i])
            makeScc(10000+i);
    }

    for(int i=1; i<=n; i++){
        if(sccNum[i]==sccNum[10000+i]){
            cout<<"0";
            return 0;
        }
    }
    cout<<"1";
    return 0;
}