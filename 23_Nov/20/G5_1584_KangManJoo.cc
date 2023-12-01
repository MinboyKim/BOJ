#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int board[501][501];
vector<piii> edge[501][501];
int visited[501][501];

int n, m, x1, Y1, x2, y2;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

priority_queue<piii,vector<piii>,greater<>> pq;

void dijkstra(pii cur, int curCost) {
    int curRow = cur.first;
    int curCol = cur.second;
    visited[curRow][curCol]=1;
    board[curRow][curCol]=curCost;

    int nRow,nCol;
    for(auto next: edge[curRow][curCol]){
        nRow = next.second.first;
        nCol = next.second.second;
        if(!visited[nRow][nCol])
            pq.push({next.first+curCost,{nRow,nCol}});
    }
}

int main() {
    cin >> n;
    while (n--) {
        cin >> x1 >> Y1 >> x2 >> y2;
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            for (int j = min(Y1, y2); j <= max(Y1, y2); j++) {
                board[i][j] = 1;
            }
        }
    }

    cin >> m;
    while (m--) {
        cin >> x1 >> Y1 >> x2 >> y2;
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            for (int j = min(Y1, y2); j <= max(Y1, y2); j++) {
                board[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            for (int k = 0; k < 4; k++) {
                if (j + dx[k] < 0 || i + dy[k] < 0 || j + dx[k] > 500 ||
                    i + dy[k] > 500)
                    continue;
                if(board[i+dy[k]][j+dx[k]]==-1) continue;
                edge[i][j].push_back(
                    {board[i + dy[k]][j + dx[k]], {i + dy[k], j + dx[k]}});
            }
        }
    }

    pq.push({0,{0, 0}});

    int curCost,curRow,curCol;
    while(!pq.empty()){
        piii cur = pq.top();
        pq.pop();
        pii curLoc = cur.second;
        curCost= cur.first;
        curRow = curLoc.first;
        curCol = curLoc.second;

        if(visited[curRow][curCol]) continue;

        dijkstra(curLoc,curCost);
    }

    if(!visited[500][500]) cout<<-1;
    else cout<<board[500][500];
}