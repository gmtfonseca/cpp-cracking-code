//
//  main.cpp
//  2_minimal_tree
//
//  Created by Gustavo Fonseca on 21/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  TODO: giving a sorted array (increasing order) write algorithm to create a
//  binary search tree with minimal height
//  input: vector
//  root of a linked list

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  TreeNode* right;
  TreeNode* left;
  int key;
  TreeNode(int k) : key(k) {}
};

TreeNode* buildTree(const vector<int>& v, int start, int end) {
  // { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
  if (start > end) {
    return nullptr;
  }
  
  int mid = (start + end) / 2;
  TreeNode* node = new TreeNode(v[mid]);
  node->left = buildTree(v, start, mid - 1);
  node->right = buildTree(v, mid + 1, end);
  return node;
}

TreeNode* getTree(const vector<int>& v) {

  return buildTree(v, 0, (int)v.size() - 1);
}

int main(int argc, const char * argv[]) {
  // insert code here...
  vector<int> v { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
  
  TreeNode* root = getTree(v);
  
  
  return 0;
}
