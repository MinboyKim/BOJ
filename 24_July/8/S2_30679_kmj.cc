#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int n, m;
int check[101][101][4];

void init(){
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            for(int dir=0; dir<4; dir++)
                check[i][j][dir] = 0;
        }
    }

}

int game(int curX, int curY){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dir = 0;

    while(true){
        if(curX < 0 || curX >= m || curY < 0 || curY >= n){
            return 0;
        }

        if(check[curY][curX][dir] == 1){
            return 1;
        }

        check[curY][curX][dir] = 1;


        curX = curX + dx[dir]*board[curY][curX];
        curY = curY + dy[dir]*board[curY][curX];

        dir = (dir + 1) % 4;
    }
}

vector<int> ans;

int main(){

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
            init();
            int curY = i, curX = 0;
            int result = game(curX, curY);
            if(result == 1){
                ans.push_back(i + 1);
                cnt++;
            }
        
    }

    cout << cnt << '\n';
    for(auto i:ans){
        cout << i << ' ';
    }
}