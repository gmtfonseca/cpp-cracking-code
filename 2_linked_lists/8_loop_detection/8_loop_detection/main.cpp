//
//  main.cpp
//  8_loop_detection
//
//  Created by Gustavo Fonseca on 01/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Input: A node of a linked list
//  Output: Begining of circular, node that points to an earlier

#include <iostream>
#include <unordered_set>
#include "../../extra/linked_list.hpp"

using namespace std;

Node* getBegining(Node* node) {
  // space = O(n)
  // time = O(n)
  unordered_set<Node*> nodes;
  
  Node* curr = node;
  while (curr != nullptr) {
    // if next node has already being looped
    if (nodes.find(curr->next()) != nodes.end()) {
      break;
    }
    // put node address into hash table
    nodes.insert(curr);
    curr = curr->next();
  }
  
  return curr;
}


void test() {

  Node* t = new Node{1, nullptr};
  Node* t2 = new Node{2, nullptr};
  Node* t3 = new Node{3, nullptr};
  
  Node* t4 = new Node{4, nullptr};
  Node* t5 = new Node{5, nullptr};
  Node* t6 = new Node{6, nullptr};
  
  t->set_next(t2);
  t2->set_next(t3);
  t3->set_next(t4);
  t4->set_next(t5);
  t5->set_next(t6);
  t6->set_next(t);
  
  cout << "Should output 6: " << getBegining(t)->value() << endl;
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
