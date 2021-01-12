#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
 public:
  Node* insert(Node* root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node* cur;
      if (data <= root->data) {
        cur = insert
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }
  /*The tree node has data, left child and right child
  class Node {
      int data;
      Node* left;
      Node* right;
  };

  */
  int height(Node* root) {
    if (!root || (!root->left and !root->right)) return 0;
    return 1 + max(height(root->left), height(root->right));
  }

};  // End of Solution