#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<int, int> pii;

pii tree[100];

void preOrder(int cur){
    int left =tree[cur].first;
    int right = tree[cur].second;

    cout<<static_cast<char>(cur);
    if(left != 46) preOrder(left);
    if(right != 46) preOrder(right);
}

void inOrder(int cur){
    int left = tree[cur].first;
    int right = tree[cur].second;

    if (left != 46) inOrder(left);
    cout << static_cast<char>(cur);
    if (right != 46) inOrder(right);
}

void postOrder(int cur) {
    int left = tree[cur].first;
    int right = tree[cur].second;

    if (left != 46) postOrder(left);
    if (right != 46) postOrder(right);
    cout << static_cast<char>(cur);
}

int main() {
  cin >> n;
  char p, l, r;

  for (int i = 0; i < n; i++) {
    cin >> p >> l >> r;
    tree[p].first = l;
    tree[p].second = r;
  }

  preOrder(65);
  cout<<'\n';
  inOrder(65);
  cout<<'\n';
  postOrder(65);

 
}