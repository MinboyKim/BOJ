#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<int> parent[101];

int solve(int cur){
    int childMax=1;

    if(!parent[cur].size()){
        return childMax;
    }

    vector<int> v;

    for(int i=0; i<parent[cur].size(); i++){
        int next=parent[cur][i];
        v.push_back(solve(next));
    }
    sort(v.begin(),v.end(),greater<>());

    int cnt=0;
    for(auto i : v){
        childMax=max(childMax,i+cnt);
        cnt++;
    }

    return childMax+1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (i == 0)
            continue;
        parent[p].push_back(i);
    }

    queue<pair<int, int>> q;
    cout<<solve(0)-1;
}