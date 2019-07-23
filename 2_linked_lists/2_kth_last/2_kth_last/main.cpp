//
//  main.cpp
//  2_kth_last
//
//  Created by Gustavo Fonseca on 27/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//

#include <iostream>
#include "../../extra/linked_list.hpp"

using namespace std;

int kthToLast(Node* head, int value) {
  
  Node* curr = head;
  Node* runner = head;
  
  // give runner the advantage
  for (unsigned i = 0; i < value; i++) {
    runner = runner->next();
  }
  
  while (runner != nullptr) {
    curr = curr->next();
    runner = runner->next();
  }
  
  return curr->value();
}

Node* kthToLastRecursive(Node* head, int k, int& index) {
  if (head == nullptr) {
    return nullptr;
  }
  
  Node* nd = kthToLastRecursive(head->next(), k, index);
  
  index += 1;
    
  if (index == k) {
    return head;
  }
  
  return nd;
}

Node* kthToLastRecursive(Node* head, int k) {
  int index = 0;
  return kthToLastRecursive(head, k, index);
}

void test() {
  Node* t = new Node{1, nullptr};
  Node* t3 = new Node{2, nullptr};
  Node* t4 = new Node{4, nullptr};
  Node* t5 = new Node{3, nullptr};
  Node* t6 = new Node{5, nullptr};
  Node* t7 = new Node{18, nullptr};
  Node* t8 = new Node{20, nullptr};
  Node* t9 = new Node{18, nullptr};
  Node* t10 = new Node{16, nullptr};
  
  t->set_next(t3);
  t3->set_next(t4);
  t4->set_next(t5);
  t5->set_next(t6);
  t6->set_next(t7);
  t7->set_next(t8);
  t8->set_next(t9);
  t9->set_next(t10);
  
  
  cout << "Should output 20: " << kthToLast(t, 3) << endl;
  cout << "Should output 20: " << kthToLastRecursive(t, 3)->value() << endl;
  
  cout << "Should output 5: " << kthToLast(t, 5) << endl;
  cout << "Should output 5: " << kthToLastRecursive(t, 5)->value() << endl;
  
  cout << "Should output 18: " << kthToLast(t, 2) << endl;
  cout << "Should output 18: " << kthToLastRecursive(t, 2)->value() << endl;
  
  cout << "Should output 16: " << kthToLast(t, 1) << endl;
  cout << "Should output 16: " << kthToLastRecursive(t, 1)->value() << endl;
}

int main(int argc, const char * argv[]) {
  test();
  
  return 0;
}
