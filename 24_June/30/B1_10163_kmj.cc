#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int score[101];
int main()
{
    int n,ax,ay,bx,by;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin>>ax>>ay>>bx>>by;
        for (int j = ax; j<ax+bx; j++){
            for (int k = ay; k<ay+by; k++){
                board[j][k] = i+1;
            }
        }
    }
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < 1001; j++){
            score[board[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++){
        cout<<score[i]<<'\n';
    }
}