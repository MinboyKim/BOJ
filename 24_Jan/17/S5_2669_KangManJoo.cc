#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int main() {
    int ax, bx, ay, by;
    for (int i = 0; i < 4; i++) {
        cin >> ax >> ay >> bx >> by;
        for (int x = ax; x < bx; x++){
            for (int y = ay; y < by; y++){
                board[x][y] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++){
            if(board[i][j]){
                cnt++;
            }
        }
    }
    cout << cnt;
}