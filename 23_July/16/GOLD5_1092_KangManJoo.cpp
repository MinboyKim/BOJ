#include <bits/stdc++.h>

using namespace std;

int crain[51];
vector<int> box;
queue<int> q;
int t;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> crain[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    box.push_back(b);
  }
  sort(box.begin(), box.end(), greater<>());
  sort(crain, crain + n, greater<>());

  if(crain[0]<box[0]){
    cout<<-1;
    return 0;
  }
  
  while (!box.empty()) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (crain[i] >= box[j]) {
          box.erase(box.begin() + j);
          m--;
          break;
        }
      }
    }
    t++;
  }
  cout<<t;
}