//
//  main.cpp
//  4_partition
//
//  Created by Gustavo Fonseca on 28/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  TODO: Partition linked list in half, every node below the argument comes to left, every node greater or EQUAL to the right

//  Input: Linked list, int value
//  Output: Linked list ordered

#include <iostream>
#include <vector>
#include "../../extra/linked_list.hpp"

using namespace std;

void partition(Node* head, int v) {
  // at least O(n)
  vector<int> less;
  vector<int> greater;
  
  Node* curr = head;
  while (curr != nullptr) {
    if (curr->value() < v) {
      less.push_back(curr->value());
    } else {
      greater.push_back(curr->value());
    }
    curr = curr->next();
  }
  
  curr = head;
  for (unsigned i = 0; i < less.size(); i++) {
    curr->set_value(less[i]);
    curr = curr->next();
  }
  
  for (unsigned i = 0; i < greater.size(); i++) {
    curr->set_value(greater[i]);
    curr = curr->next();
  }
  
}

// cool solution, the head grows to the left, the tail to the right. Both start from the same node.
Node* partitionBook(Node* node, int v) {
  Node* head = node;
  Node* tail = node;
  
  Node* curr = head;
  while (curr != nullptr) {
    Node* next = curr->next();
    if (curr->value() < v) {
      curr->set_next(head);
      head = curr;
    }
    else {
      tail->set_next(curr);
      tail = curr;
    }
    curr = next;
  }
  tail->set_next(nullptr);
  
  return head;
}

void output(Node* first) {
  Node* curr = first;
  while(curr != nullptr) {
    cout << curr->value() << "->";
    curr = curr->next();
  }
  cout << endl;
}

void test() {
  Node* t = new Node{20, nullptr};
  Node* t3 = new Node{4, nullptr};
  Node* t4 = new Node{17, nullptr};
  Node* t5 = new Node{27, nullptr};
  Node* t6 = new Node{8, nullptr};
  Node* t7 = new Node{16, nullptr};
  Node* t8 = new Node{9, nullptr};
  Node* t9 = new Node{4, nullptr};
  Node* t10 = new Node{3, nullptr};
  
  t->set_next(t3);
  t3->set_next(t4);
  t4->set_next(t5);
  t5->set_next(t6);
  t6->set_next(t7);
  t7->set_next(t8);
  t8->set_next(t9);
  t9->set_next(t10);
  
  output(t);
  
  //partition(t, 8);
  Node* c = partitionBook(t, 8);
  output(c);
  
  
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
