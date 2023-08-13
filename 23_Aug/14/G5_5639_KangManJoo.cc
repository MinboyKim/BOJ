#include <bits/stdc++.h>

using namespace std;

int tree[10001];

class Node {
 public:
  int value;
  Node* parent = nullptr;
  Node* left;
  Node* right;
};

class Tree {
 public:
  int left;
  int right;
  Node* root = nullptr;

  void insert(int v);
};

void Tree::insert(int v) {
  Node* newNode->value=v;
  if (root == nullptr) {
    root->value = v;
  } else {
    int cur = root->value;
    Node* next=root;

    while (true) {
      if (cur > v) {
        next=next->left;
        if(next->value){
            cur=next->value;
        }
        else{
            break;
        }
      }
      else if(cur < v){
        next = next->right;
        if (next->value) {
            cur = next->value;
        } else {
            
            break;
        }
      }
    }




  }
}

int main() {
  int cur;
  Tree tree;

  while (!(cin >> cur).eof()) {
    tree.insert(cur);
  }
}