#include <bits/stdc++.h>

using namespace std;

int remote[10];
int minMove = 999999;
int main() {
  int n, m, t;
  cin >> n >> m;
  while (m--) {
    cin >> t;
    remote[t] = -1;
  }

  int justMove = abs(100 - n);
  int cantGo;
  for (int i = 0; i <= 999999; i++) {
    cantGo=0;
    string s = to_string(i);
    for (auto c : s) {
      if (remote[c - 48] == -1) {
        cantGo=1;
        break;
      }
    }
    if(cantGo) continue;
    int target = n - stoi(s);
    int length = s.length();
    minMove = min(minMove, (abs(target) + length));
  }

  cout << min(justMove, minMove);
}