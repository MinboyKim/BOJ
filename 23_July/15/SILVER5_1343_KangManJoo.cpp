#include <bits/stdc++.h>

using namespace std;

string s;
int arr[51];
vector<char> v;

int main() {
  cin >> s;
  int i = 0;
  for (auto a : s) {
    if (a == 'X') {
      arr[i] = 1;
    } else {
      arr[i] = 0;
    }
    i++;
  }

  int cnt = 0;
  for (int j = 0; j < i; j++) {
    if (arr[j] == 1) {
      cnt++;
      continue;
    } else {
      if (cnt == 0) {
        v.push_back('.');
      } else if (cnt % 2 != 0) {
        cout << -1;
        return 0;
      } else {
        int a = (cnt / 4) * 4;
        while (a--) {
          v.push_back('A');
        }
        int b = (cnt % 4);
        while (b--) {
          v.push_back('B');
        }
        v.push_back('.');
      }
      cnt = 0;
    }
  }
  if (cnt != 0) {
    if (cnt % 2 != 0) {
      cout << -1;
      return 0;
    } else {
      int a = (cnt / 4) * 4;
      while (a--) {
        v.push_back('A');
      }
      int b = (cnt % 4);
      while (b--) {
        v.push_back('B');
      }
    }
  }
  for(auto i: v){
    cout<<i;
  }
}