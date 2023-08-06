#include <bits/stdc++.h>

using namespace std;

int n, m, num, k, knowNum, knowHuman;
int know[51];
int party[51];
vector<int> participant[51];
int Union[51];
int fake[51];

int findUnion(int cur) {
  if (cur == Union[cur])
    return cur;
  else {
    return findUnion(Union[cur]);
  }
}

void makeUnion(int a, int b) {
  if(findUnion(a)==findUnion(b)) return;

  if (know[Union[a]] == 1) {
    b = findUnion(b);
    Union[b] = Union[a];
  } else {
    a = findUnion(a);
    Union[a] = Union[b];
  }
}

void makePair(int cur) {
  for (int i = 0; i < participant[cur].size() - 1; i++) {
    int pre = participant[cur][i];
    int next = participant[cur][i + 1];
    makeUnion(pre, next);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  cin >> knowNum;

  while (knowNum--) {
    cin >> knowHuman;
    know[knowHuman] = 1;
  }

  for (int i = 1; i <= n; i++) {
    Union[i] = i;
  }


  for (int i = 1; i <= m; i++) {
    cin >> num;
    while (num--) {
      cin >> k;
      participant[i].push_back(k);
    }
    makePair(i);
  }
  for( int i=1; i<=n; i++){
    if(know[Union[i]]==1){
        fake[i]=1;
    }
  }

  int cnt = 0;
  bool lye;
  for (int i = 1; i <= m; i++) {
    lye = false;
    for (int j = 0; j < participant[i].size(); j++) {
        int next = participant[i][j];
      if (fake[next] == 1) {
        lye = true;
        break;
      }
    }
    if (!lye) cnt++;
  }

  cout << cnt;
}