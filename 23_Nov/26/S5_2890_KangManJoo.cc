#include <bits/stdc++.h>

using namespace std;

char board[51][51];
pair<int,int> ranking[10];
int newRank[10];
int main(){
    int r,c;
    string str;
    cin>>r>>c;
    for(int i=0; i<r; i++){
        cin>>str;
        for(int j=0; j<str.size(); j++){
            board[i][j]=str[j];
        }
    }
    for (int i = 1; i < 10; i++) {
        ranking[i].second=i;
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j]>=48 && board[i][j]<=57){
                ranking[int(board[i][j])-48].first=j;
                break;
            }
        }
    }

    sort(ranking,ranking+10,greater<>());

    newRank[ranking[0].second] = 1;
    for(int i=1; i<9; i++){
        if(ranking[i].first==ranking[i-1].first){
            newRank[ranking[i].second]=newRank[ranking[i-1].second];
        }
        else{
            newRank[ranking[i].second] = newRank[ranking[i - 1].second]+1;
        }
    }

    for(int i=1; i<10; i++){
        cout<<newRank[i]<<'\n';
    }
}