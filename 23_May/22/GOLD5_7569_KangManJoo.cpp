#include <bits/stdc++.h>

using namespace std;

int a,b,c;
int board[105][105][105];
typedef tuple<int,int,int> tiii;
queue<tiii> yTomato;

void bfs(){
    tiii cur;
    while(!yTomato.empty()){
        cur=yTomato.front();
        yTomato.pop();
        if(board[get<0>(cur)-1][get<1>(cur)][get<2>(cur)]==0){
            board[get<0>(cur)-1][get<1>(cur)][get<2>(cur)]=board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            yTomato.push({get<0>(cur)-1,get<1>(cur),get<2>(cur)});
        }
        if(board[get<0>(cur)+1][get<1>(cur)][get<2>(cur)]==0){
            board[get<0>(cur)+1][get<1>(cur)][get<2>(cur)]=board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            yTomato.push({get<0>(cur)+1,get<1>(cur),get<2>(cur)});
        }
        if(board[get<0>(cur)][get<1>(cur)-1][get<2>(cur)]==0){
            board[get<0>(cur)][get<1>(cur)-1][get<2>(cur)]=board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            yTomato.push({get<0>(cur),get<1>(cur)-1,get<2>(cur)});
        }
        if(board[get<0>(cur)][get<1>(cur)+1][get<2>(cur)]==0){
            board[get<0>(cur)][get<1>(cur)+1][get<2>(cur)]=board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            yTomato.push({get<0>(cur),get<1>(cur)+1,get<2>(cur)});
        }
        if(board[get<0>(cur)][get<1>(cur)][get<2>(cur)-1]==0){
            board[get<0>(cur)][get<1>(cur)][get<2>(cur)-1]=board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            yTomato.push({get<0>(cur),get<1>(cur),get<2>(cur)-1});
        }
        if(board[get<0>(cur)][get<1>(cur)][get<2>(cur)+1]==0){
            board[get<0>(cur)][get<1>(cur)][get<2>(cur)+1]=board[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            yTomato.push({get<0>(cur),get<1>(cur),get<2>(cur)+1});
        }
    }
    return;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>b>>a>>c;
    for(int k=1; k<=c; k++){
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                cin>>board[k][i][j];
                if(board[k][i][j]==1){
                    yTomato.push({k,i,j});
                }
            }
        }
    }

    for(int i=1; i<=c; i++){
         for(int j=1; j<=a; j++){
            board[i][j][0]=-1;
            board[i][j][b+1]=-1;
         }
    }

    for(int i=1; i<=c; i++){
         for(int j=1; j<=b; j++){
            board[i][0][j]=-1;
            board[i][a+1][j]=-1;
         }
    }
     for(int i=1; i<=a; i++){
         for(int j=1; j<=b; j++){
            board[0][i][j]=-1;
            board[c+1][i][j]=-1;
         }
    }

    bfs();

    int cnt=0;
     for(int k=1; k<=c; k++){
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                if(board[k][i][j]==0){
                    cout<<"-1";
                    return 0;
                }
                cnt=max(cnt,board[k][i][j]);
            }
        }
     }
    cout<<cnt-1;

    return 0;
}