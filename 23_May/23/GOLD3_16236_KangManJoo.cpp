#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n;
int board[22][22];
pii start;
int curSize=2;
int moved;
int visited[22][22];
int turn[22][22];
int lvUp;

struct compare{
    bool operator()(pii a, pii b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return a.first>b.first;
        }
    }
};

priority_queue<pii,vector<pii>,compare> nextNode;

//같은 거리라면 , 가장 위에 있고, 가장 왼쪽에 있는 것을 우선으로 먹는다.
void bfs(){
    queue<pii> q;
    pii curLoc=start;
    board[curLoc.first][curLoc.second]=0;
    while(true){
        int flag=0;
        q.push(curLoc);
        turn[curLoc.first][curLoc.second]=0;
        visited[curLoc.first][curLoc.second]=1;
        
        if(lvUp==curSize) {
            lvUp=0; 
            curSize++;
        }
        int nMove=999;

        while(!q.empty()){
            
            int x,y;
            x=q.front().first; y=q.front().second;
            q.pop();
            if(nMove<turn[x][y]) continue;


            if(x!=0 && (board[x-1][y]==0 || board[x-1][y]==curSize)){
                if(!visited[x-1][y]){
                    q.push({x-1,y});
                    turn[x-1][y]=turn[x][y]+1;
                    visited[x-1][y]=1;
              }
            }
            else if(x!=0 && board[x-1][y]<curSize){
                curLoc={x-1,y};
                flag=1;
                nMove=turn[x][y];
                nextNode.push({x-1,y});
            }
            if(y!=0 && (board[x][y-1]==0 || board[x][y-1]==curSize)){
                if(!visited[x][y-1]){
                    q.push({x,y-1});
                    turn[x][y-1]=turn[x][y]+1;
                    visited[x][y-1]=1;
              }
            }
            else if(y!=0 && board[x][y-1]<curSize){
                curLoc={x,y-1};
                flag=1;
                nMove=turn[x][y];
                nextNode.push({x,y-1});
            }
            if(y!=n-1 && (board[x][y+1]==0 || board[x][y+1]==curSize)){
                if(!visited[x][y+1]){
                    q.push({x,y+1});
                    turn[x][y+1]=turn[x][y]+1;
                    visited[x][y+1]=1;
                }
            }
            else if(y!=n-1 && board[x][y+1]<curSize){
                curLoc={x,y+1};
                flag=1;
                nMove=turn[x][y];
                nextNode.push({x,y+1});

            }
            if(x!=n-1 && (board[x+1][y]==0 || board[x+1][y]==curSize)){
                if(!visited[x+1][y]){
                    q.push({x+1,y});
                    turn[x+1][y]=turn[x][y]+1;
                    visited[x+1][y]=1;
              }
            }
            else if(x!=n-1 && board[x+1][y]<curSize){
                curLoc={x+1,y};
                flag=1;
                nMove=turn[x][y];
                nextNode.push({x+1,y});       
            }
            
        }
        if(flag==0){
            break;
        }
            
        while(!q.empty()) q.pop();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=0;
            }
        }
        curLoc=nextNode.top();
        board[curLoc.first][curLoc.second]=0;
        while(!nextNode.empty()) nextNode.pop();

        moved+=nMove+1;
        lvUp++;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                start.first=i; start.second=j;
            }
        }
    }

    bfs();
    cout<<moved;

}