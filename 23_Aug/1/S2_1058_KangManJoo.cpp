#include <bits/stdc++.h>
#define INF 210000000

using namespace std;
int n;
string s;
int arr[51][51];
int checked[51][51];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'N') {
        arr[i][j + 1] = INF;
      } else {
        arr[i][j + 1] = 1;
      }
      if(i==j+1){
        arr[i][j+1]=0;
      }
    }
  }
  int Max = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
            arr[i][k] = min(arr[i][k],arr[i][j]+arr[j][k]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int cnt=0;
    for (int j = 1; j <= n; j++) {
        if(arr[i][j]==1 || arr[i][j]==2) cnt++;
    }
    Max=max(Max, cnt);
  }
  cout << Max;
}