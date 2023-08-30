#include <bits/stdc++.h>

using namespace std;

int t, n, m, c;

class Node {
 public:
  int val;
  Node *leftChild;
  Node *rightChild;

  Node(int val) {
    this->val = val;
    leftChild = nullptr;
    rightChild = nullptr;
  }
};

class Tree {
 public:
  Node *root;

 public:
  Tree() { root = nullptr; }
  void insert(int x);
  void preOrder(Node *curNode);
};

void Tree::insert(int x) {
  if (this->root == nullptr) {
    root = new Node(x);
  } else {
    Node *tmp = root;
    while (true) {
      if (tmp->val > x) {
        if (tmp->leftChild == nullptr) {
          tmp->leftChild = new Node(x);
          break;
        }
        tmp = tmp->leftChild;
      } else {
        if (tmp->rightChild == nullptr) {
          tmp->rightChild = new Node(x);
          break;
        }
        tmp = tmp->rightChild;
      }
    }
  }
}

void Tree::preOrder(Node *curNode) {
  if (curNode->leftChild != nullptr) {
    preOrder(curNode->leftChild);
  }
  if (curNode->rightChild != nullptr) {
    preOrder(curNode->rightChild);
  }
  cout << curNode->val << '\n';
}

int main() {
  Tree tree;
  int cur;
  while (!(cin >> cur).eof()) {
    tree.insert(cur);
  }

  tree.preOrder(tree.root);
}