#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int N, ans;
pii Arr[55];
int minX = 9999, maxX = -9999, minY = 9999, maxY = -9999;
pii minXp,minYp;
pii maxYp,maxXp;
int flag;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    Arr[i] = {a, b};
    if (minX > a) minX = a; minXp=Arr[i];  //최대최소 업뎃
    if (maxX < a) maxX = a; maxXp=Arr[i];
    if (minY > b) {
        minY = b; minYp=Arr[i];
        if(minX!=a || maxX!=a) flag=1;
    }
    if (maxY < b) {
        maxY = b;
        if(minX!=a || maxX!=a) flag=1;
    }
    if(minX==a || maxX==a){
        if(minY!=b || maxY!=b) flag=1;

    }
  }

  ans = maxX - minX;
  if (ans != maxY - minY) {  //정사각형체크
    if(flag==1 ){
        cout << -1 << "\n";
        return 0;
    }
  }

  for (int i = 0; i < N; i++) {
    int x = Arr[i].first;
    int y = Arr[i].second;
    if ((x == minX || x == maxX) && (y >= minY && y <= maxY)) continue;
    if ((y == minY || y == maxY) && (x >= minX && x <= maxX)) continue;
    cout << -1 << "\n";
    return 0;
  }

  cout << ans << "\n";

  return 0;
}