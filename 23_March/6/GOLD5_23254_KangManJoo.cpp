#include <bits/stdc++.h>

using namespace std;

int n,m;
typedef pair<int,int> pii;
pii arr[202020];
int isUpdate[202020];

struct cmp{
    bool operator()(pii a, pii b){
        return a.second<b.second;
    }
};

priority_queue<pii,vector<pii>,cmp> pq;

int main(){
    cin>>n>>m;
    n*=24;
    for(int i=0; i<m; i++){
        cin>>arr[i].first;
    }  
     for(int i=0; i<m; i++){
        cin>>arr[i].second;
    }    
    for(int i=0; i<m; i++) pq.push(arr[i]);
    
    pii tmp;
    int score=0;
    while(!pq.empty()&&n){
        tmp=pq.top();
        pq.pop();

        while(n){
            if(tmp.first+tmp.second>100) break;
            tmp.first+=tmp.second;
            n--;
        }

        if(tmp.first==100) score+=100;
        else{
            tmp.second=100-tmp.first;
            pq.push(tmp);
            continue;
        }
    }

    while(!pq.empty()){
        score+=pq.top().first;
        pq.pop();
    }
    cout<<score;

    return 0;
}