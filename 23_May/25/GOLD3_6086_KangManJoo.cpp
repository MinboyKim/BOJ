#include <bits/stdc++.h>

using namespace std;

int n,sum;
int capacity[70][70];
int flow[70][70];
int source=1,sink=26; 
int parent[70];
//A=65 Z=90  => A=1, Z=26
//z= 122
queue<int> Q;

void maxFlow(){
    while(true){
        for(int i=0; i<70; i++){
            parent[i]=-1;
        }
        parent[source]=source;
        Q.push(source);
        while(!Q.empty()){
            int cur=Q.front();
            Q.pop();
            for(int next=0; next<70; next++){
                if(capacity[cur][next]>flow[cur][next] && parent[next]==-1){
                    Q.push(next);
                 parent[next]=cur;
                    if(next==sink) break;
                }
            }
        }
        if(parent[sink]==-1) break; // 더이상 sink로 가는 경로중 잔여용량이 남은게 존재하지 않을경우
        int cur=sink;
        int minflow=1010;
        while(cur!=source){
            int next=parent[cur];
            int residualCapa=capacity[next][cur]-flow[next][cur];
            if(residualCapa>0 &&(minflow>residualCapa)) {
                minflow=residualCapa;
            }
            cur=parent[cur];
        }
        cur=sink;
        while(cur!=source){
            int next=parent[cur];
            flow[next][cur]+=minflow;
            flow[cur][next]-=minflow;
            cur=parent[cur];
        }
        sum+=minflow;
    }
}

int main(){
    char Pnode,Nnode;
    int capa;
    cin>>n;
    while(n--){
        cin>>Pnode>>Nnode>>capa;
        capacity[Pnode-64][Nnode-64]+=capa;
        capacity[Nnode-64][Pnode-64]+=capa;
    }

    maxFlow();
    cout<<sum;
    return 0;
}