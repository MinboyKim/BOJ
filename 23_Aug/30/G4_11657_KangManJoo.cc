#include <bits/stdc++.h>

using namespace std;

#define MAX 200000000

typedef pair<int, int> pii;
int n, m;
vector<pair<pii, int>> edge;
long long dist[505];

bool bellman() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < edge.size(); j++) {
      int S = edge[j].first.first;
      int E = edge[j].first.second;
      int cost = edge[j].second;

      long long moveCost = dist[S] + cost;
      if(dist[S]==MAX) continue;
      if (moveCost < dist[E]) dist[E] = moveCost;
    }
  }

  for (int j = 0; j < edge.size(); j++) {
    int S = edge[j].first.first;
    int E = edge[j].first.second;
    int cost = edge[j].second;

    long long moveCost = dist[S] + cost;
    if (dist[S] == MAX) continue;

    if (moveCost < dist[E]) {
      cout << -1;
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n >> m;

  int S, E, cost;
  while (m--) {
    cin >> S >> E >> cost;
    edge.push_back({{S, E}, cost});
  }

  for (int i = 2; i <= n; i++) {
    dist[i] = MAX;
  }

  if(!bellman()){
    return 0;
  }
  else{
    for(int i=2; i<=n; i++){
        if(dist[i]==MAX) cout<<-1<<'\n';
        else cout<<dist[i]<<'\n';
    }
  }
}