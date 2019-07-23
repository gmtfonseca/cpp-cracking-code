//
//  main.cpp
//  3_delete_middle
//
//  Created by Gustavo Fonseca on 28/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Delete middle node (not first nor last), given only access to it.

// ITS THE FUCKING DESTRUCTOR DESTROYING EVERYTHING

#include <iostream>
#include "../../extra/linked_list.hpp"

using namespace std;

bool deleteMiddle(Node* middle) {
  
  if (middle == nullptr || middle->next() == nullptr) return false;
  
  Node* next = middle->next();

  middle->set_value(next->value());
  middle->set_next(next->next());

  delete next;
  
  return true;
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
  Node* t = new Node{1, nullptr};
  Node* t3 = new Node{2, nullptr};
  Node* t4 = new Node{8, nullptr};
  Node* t5 = new Node{3, nullptr};
  Node* t6 = new Node{4, nullptr};
  Node* t7 = new Node{16, nullptr};
  Node* t8 = new Node{9, nullptr};
  Node* t9 = new Node{10, nullptr};
  Node* t10 = new Node{18, nullptr};
  
  t->set_next(t3);
  t3->set_next(t4);
  t4->set_next(t5);
  t5->set_next(t6);
  t6->set_next(t7);
  t7->set_next(t8);
  t8->set_next(t9);
  t9->set_next(t10);
  
  output(t);
  
  // delete 4
  deleteMiddle(t3);
  
  output(t);
  // 1 -> 2 -> 8 -> 3 -> 16 -> 9 -> 10 -> 18
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}

