#include <bits/stdc++.h>
using namespace std;

int t, n, m, q, a;
pair<int, int> colMax[200001];
int rowMax[200001];
vector<vector<int>> board;
vector<int> v;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  cin >> t;

//   vector<int> dummy;
//   board.push_back(dummy);
//   v.push_back(1);
  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
      colMax[i] = {0, 0};
    }

    // rowMax 배열 초기화
    for (int i = 1; i <= n; i++) {
      rowMax[i] = 0;
    }

    //vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
      int MAX = 0;
    //   for (int j = 1; j <= m; j++) {
    //     cin >> a;
    //     if (colMax[j].first < a) {
    //       colMax[j].first = a;
    //     }
    //     if (MAX < a) MAX = a;
    //     //v.push_back(a);
    //   }
      rowMax[i] = MAX;
      //board.push_back(v);
    }

    int sum = 0;

    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= m; j++) {
    //     if (board[i][j] == rowMax[i] && board[i][j] == colMax[j].first) {
    //       colMax[j].second++;
    //     }
    //   }
    // }

    // while (q--) {
    //   int x, y, cost;
    //   cin >> x >> y >> cost;
    //   board[x][y] = cost;
    //   if (rowMax[x] < cost) {
    //     for (int i = 1; i <= m; i++) {
    //       if (board[x][i] == rowMax[x] && colMax[i].first == rowMax[x]) {
    //         colMax[i].second--;
    //       }
    //     }
    //     rowMax[x] = cost;
    //   }
    //   if (colMax[y].first < cost) {
    //     colMax[y].first = cost;
    //     colMax[y].second = 1;
    //   } else if (colMax[y].first == cost) {
    //     colMax[y].second++;
    //   }

    //   for (int i = 1; i <= m; i++) {
    //     sum += colMax[i].second;
    //   }
    // }
    cout << "#" << tc << " " << sum << "\n";
  }
}