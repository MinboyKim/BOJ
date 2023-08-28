#include <bits/stdc++.h>

//음의 순환이 있는지 확인 
#define INF 210000000
using namespace std;
typedef pair<int,int> pii;

int t, n, m, w;
vector<pair<pii,int>> edge;
int dist[505];

void init() {
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  while(!edge.empty()){
    edge.pop_back();
  }
}

void solve() {
  int Pnode, Nnode, cost;
  cin >> m >> w;

  while(m--){
    cin>>Pnode>>Nnode>>cost;
    edge.push_back({{Pnode,Nnode},cost});
    edge.push_back({{Nnode,Pnode},cost});
  }

  while(w--){
    cin>>Pnode>>Nnode>>cost;
    edge.push_back({{Pnode, Nnode}, -cost});
  }

  dist[1]=0;

  for(int i=0; i<n-1; i++){
    for(int j=0; j<edge.size(); j++){
        int S = edge[j].first.first;
        int E = edge[j].first.second;
        int cost = edge[j].second;

        // if(dist[S]==INF) continue;
        if(dist[S]+cost<dist[E]) dist[E]=dist[S]+cost;
    }
  }
  int flag=0;
  for (int j = 0; j < edge.size(); j++) {
    int S = edge[j].first.first;
    int E = edge[j].first.second;
    int cost = edge[j].second;

    // if (dist[S] == INF) continue;
    if (dist[S] + cost < dist[E]){
        flag=1;
        break;
    }
  }

  if(flag) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    init();
    solve();
  }
}