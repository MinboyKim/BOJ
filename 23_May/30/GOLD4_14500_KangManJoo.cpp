#include <bits/stdc++.h>

using namespace std;

int row,col;
int board[505][505];
int checked[505][505];
int visited[505][505];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int MAX;
int curCost;
void solve(int r,int c,int cnt){
    visited[r][c]=1;
    int newR,newC;
    curCost+=board[r][c];

    if(cnt==1){
            int cross=board[r][c]+board[r+1][c]+board[r-1][c]+board[r][c+1]+board[r][c-1];
             for(int i=0; i<4; i++){
                newR=r+dx[i];
                newC=c+dy[i];
                if(cross-board[newR][newC]>MAX) MAX=cross-board[newR][newC];
        }
    }
    if(cnt==4){
        MAX=(MAX<curCost) ? curCost : MAX; 
        curCost-=board[r][c];
         visited[r][c]=0;
        return;
    }

    for(int i=0; i<4; i++){
        newR=r+dx[i];
        newC=c+dy[i];

        if(newR==0||newC==0||newR>row || newC>col) continue;
        if(!visited[newR][newC]){
            //visited[newR][newC]=1;
            solve(newR,newC,cnt+1);
            //visited[newR][newC]=0;
        }
    }
    curCost-=board[r][c];
    visited[r][c]=0;
    return;
}


int main(){
    cin>>row>>col;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin>>board[i][j];
        }
    }
     for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            checked[i][j]=1;
            solve(i,j,1);
            curCost=0;
        }
     }

     cout<<MAX;

}