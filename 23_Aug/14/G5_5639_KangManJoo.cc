#include <bits/stdc++.h>

using namespace std;

int tree[10001];

class Node {
 public:
  int value;
  Node* left;
  Node* right;

  Node(int value) { this->value = value; }
};

class Tree {
 public:
  Node* root;

  Tree() { root = nullptr; }

  void insert(int v);
};

void Tree::insert(int v) {
  Node newNode(v);

  if (root == nullptr) {
    root = new Node(v);
  } else {
    int cur = root->value;
    Node* next = root;

    while (true) {
      if (cur > v) {
        next = next->left;
        if (next->value) {
          cur = next->value;
        } else {
          next = &newNode;
          break;
        }
      } else if (cur < v) {
        next = next->right;
        if (next->value) {
          cur = next->value;
        } else {
          next = &newNode;
          break;
        }
      } else {
        break;
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

  cout << "asd";
}