#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;
typedef pair<int,int> pii;
int visited[200200];

int solve()
{
    queue<pii> q;
    q.push({n,0});
    int lv = 0;
    while (!q.empty()){
        pii cur = q.front();
        q.pop();
        visited[cur.first]=1;
        if(cur.first==k) {
            return cur.second;
        }
        if(cur.first>k){
            if(!visited[cur.first-1]) q.push({cur.first - 1,cur.second+1});
        }
        else if (cur.first>=0){
            if(!visited[cur.first-1])q.push({cur.first - 1,cur.second+1});
            if(!visited[cur.first+1])q.push({cur.first + 1,cur.second+1});
            if(!visited[cur.first*2])q.push({cur.first*2,cur.second+1});
        }
    }
    return -1;
}

int main()
{
    cin >> n >> k;

    cout << solve();
}