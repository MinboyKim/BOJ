#include <bits/stdc++.h>

using namespace std;

int arr[10];

int n,m;
vector<int> v;


void dfs(int cur,int cnt){
    if(cnt == m){    
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<"\n";
        return ;
    }

    for(int i=cur; i<=n; i++){
        v.push_back(i);
        dfs(i,cnt+1);
        v.pop_back();
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>m;


    dfs(1,0);
}