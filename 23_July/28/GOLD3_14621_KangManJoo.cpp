#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pip;
int n,m,result;
char sex;
int schoolSex[1001];
vector<int> node[1001];
int Union[1001];

priority_queue<pip,vector<pip>,greater<pip>> pq;

int findUnion(int cur){
    if(Union[cur] == cur) return cur;
    else{
        return findUnion(Union[cur]);
    }
}

void MakeUnion(int a, int b){
    b = findUnion(b);

    Union[b] = findUnion(a);
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>sex;
        if(sex=='M'){
            schoolSex[i] = 1; //male
        }
        else{
            schoolSex[i] = 2; //female
        }
        Union[i] = i;
    }

    int Pnode,Nnode,cost;
    while(m--){
        cin>>Pnode>>Nnode>>cost;
        if(schoolSex[Pnode] == schoolSex[Nnode]) continue;
        
        pq.push({cost,{Pnode,Nnode}});
    }

    while(!pq.empty()){
        pip cur = pq.top();
        pq.pop();

        Pnode = cur.second.first;
        Nnode = cur.second.second;
        if(findUnion(Pnode) == findUnion(Nnode)) continue;
        else{
            MakeUnion(Pnode,Nnode);
            result += cur.first;
        }
    }

    int Groub = findUnion(1);
    for(int i=2; i<=n; i++){
        if(Groub != findUnion(i)){
            cout<<-1;
            return 0;
        }
    }

    cout<<result;
    return 0;
}