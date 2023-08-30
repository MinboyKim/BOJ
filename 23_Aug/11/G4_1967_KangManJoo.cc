#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> node[20200];
int longerSum;
int visited[20200];

int dfs(int cur,int cost){
    visited[cur]=1;
    int childSum=0,childLength=0, childLongestLength=0,childSecondLongLength=0;

    for(int i=0; i<node[cur].size(); i++){
        int next=node[cur][i].first;
        if(!visited[next]){
            int childLength = dfs(node[cur][i].first,node[cur][i].second);
            if(childLength>childSecondLongLength){
                childSecondLongLength=childLength;
                if(childSecondLongLength>childLongestLength){
                    swap(childLongestLength,childSecondLongLength);
                }
            }
        }
    }

    childSum=childLongestLength+childSecondLongLength;
    if(childSum>longerSum) longerSum = childSum;
    return childLongestLength+cost;
}

int main(){
    int n;
    int Pnode,Nnode,cost;
    cin>>n;
    for(int i=1; i<n; i++){
        cin>>Pnode>>Nnode>>cost;
        node[Pnode].push_back({Nnode,cost});
    }

    int childSum=dfs(1,0);
    if (childSum > longerSum) longerSum = childSum;

    cout<<longerSum;
}