#include <bits/stdc++.h>

using namespace std;

int board[100][100];

int main(){
    int n,x,y;
    cin>>n;
    while(n--){
        cin>>x>>y;
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++)
             board[i][j]=1;
        }
    }

    int cnt=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(board[i][j]) cnt++;
        }
    }

    cout<<cnt;
}