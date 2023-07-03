#include <iostream>
#include <vector>
#include <string>

using namespace std;

char board[101][101];
char board2[101][101];

vector<string> arr;
int visited[101][101];
int visited2[101][101];

int n;

void dfs(int row, int col,int flag){
    char (*brd)[101];
    int (*visit)[101];
    if(flag==1){
        brd=board;
        visit=visited;
    }
    else{
        brd=board2;
        visit=visited2;
    }

    char cur=brd[row][col];
    visit[row][col]=1;

    if(brd[row-1][col]==cur){
        if(!visit[row-1][col]){
            dfs(row-1,col,flag);
        }
    }
    if(brd[row+1][col]==cur){
        if(!visit[row+1][col]){
            dfs(row+1,col,flag);
        }
    }
    if(brd[row][col+1]==cur){
        if(!visit[row][col+1]){
            dfs(row,col+1,flag);
        }
    }
    if(brd[row][col-1]==cur){
        if(!visit[row][col-1]){
            dfs(row,col-1,flag);
        }
    }
    return;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string col;
        cin>>col;
        arr.push_back(col);
    }    

    for(int i=0; i<n; i++){
        int j=0;
        for(auto val:arr[i]){
            board[i+1][j+1]=val;    //1~n까지 기록 col또는 row가 0인 곳은 비운다.
            if(val=='G'){
                board2[i+1][j+1]='R';  //색맹이 g를 보면 R로 치환
            }
            else{
                board2[i+1][j+1]=val;
            }
            j++;
        }
    }

    int normal=0;
    int abnormal=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visited[i][j]){
                dfs(i,j,1);
                normal++;
            }
            if(!visited2[i][j]){
                dfs(i,j,2);
                abnormal++;
            }
        }
    }
    cout<<normal<<" "<<abnormal;
}