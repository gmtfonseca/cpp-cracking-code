//
//  main.cpp
//  1_remove_dups
//
//  Created by Gustavo Fonseca on 26/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//
//  Remove duplicates from unsorted linked list
//  without temporary buffer
//  input: linked list
//  ouput: linked list without duplicate

#include <iostream>
#include <vector>
#include "../../extra/linked_list.hpp"

using namespace std;


// brute force
void removeDuplicates(Node* first) {
  Node* curr = first;
  while(curr != nullptr) {
    
    Node* runner = curr;
    while(runner->next() != nullptr) {
      if (runner->next()->value() == curr->value()) {
        runner->set_next(runner->next()->next());
      } else {
        // ?
        runner = runner->next();
      }
      
    }
    
    curr = curr->next();
  }
}

void test() {
}

void output(Node* first) {
  Node* curr = first;
  while(curr != nullptr) {
    cout << curr->value() << "->";
    curr = curr->next();
  }
  cout << endl;
}

int main(int argc, const char * argv[]) {
  Node* t = new Node{1, nullptr};
  Node* t3 = new Node{2, nullptr};
  Node* t4 = new Node{1, nullptr};
  Node* t5 = new Node{3, nullptr};
  Node* t6 = new Node{4, nullptr};
  Node* t7 = new Node{1, nullptr};
  Node* t8 = new Node{2, nullptr};
  Node* t9 = new Node{2, nullptr};
  Node* t10 = new Node{1, nullptr};
  t->set_next(t3);
  t3->set_next(t4);
  t4->set_next(t5);
  t5->set_next(t6);
  t6->set_next(t7);
  t7->set_next(t8);
  t8->set_next(t9);
  t9->set_next(t10);
  
  output(t);
  
  removeDuplicates(t);
  
  output(t);

  return 0;
}
