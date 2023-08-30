#include <bits/stdc++.h>
#define INF 200000000
using namespace std;
typedef pair<int,int> pii;


int n,m;
int minCost[1001][1001];

void init(){
    int preNode,nNode,cost;
    fill(&minCost[0][0],&minCost[101][101],INF);
    while(m--){
        cin>>preNode>>nNode>>cost;
        minCost[preNode][nNode]=min(minCost[preNode][nNode],cost);
    }
}

void solve(){
    for(int transfer=1; transfer<=n; transfer++){
        for(int pNode=1; pNode<=n; pNode++){
           for(int nNode=1; nNode<=n; nNode++){
               if(pNode==nNode) {
                continue;
                }
                if(pNode==transfer||nNode==transfer) continue;
                minCost[pNode][nNode]=min(minCost[pNode][nNode],minCost[pNode][transfer]+minCost[transfer][nNode]);
                }
            }
    }

}
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n>>m;
    init();
    solve();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(minCost[i][j]==INF) cout<<0<<" ";
            else cout<<minCost[i][j]<<" ";
        }
        cout<<"\n";
    }
}