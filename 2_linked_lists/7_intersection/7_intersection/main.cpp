//
//  main.cpp
//  7_intersection
//
//  Created by Gustavo Fonseca on 01/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Input: Two singly linked lists
//  Output: Intersecting node

//  Example: 3 -> 2 -> 4 -> |5| -> 1 -> 4 -> 10
//           7 -> 8 -> 5 ->  1 ->  4 -> 10


#include <iostream>
#include <math.h>
#include "../../extra/linked_list.hpp"

using namespace std;

struct Result {
  Node* tail;
  int size;
  Result(Node* t, int s) : tail(t), size(s) {};
};

Result getTailAndSize(Node* head) {
  
  if (head == nullptr) return Result(nullptr, 0);
  
  Node* curr = head;
  int size = 0;
  
  while (curr->next() != nullptr) {
    size++;
    curr = curr->next();
  }
  
  return Result{curr, size};
}

Node* advanceToKth(Node* node, int k) {
  while (k > 0 and node != nullptr) {
    node = node->next();
    k--;
  }
  return node;
}

Node* getIntersection(Node* first, Node* second) {
  // pre conditions
  if (first == nullptr || second == nullptr) return nullptr;
  
  Result firstProps = getTailAndSize(first);
  Result secondProps = getTailAndSize(second);
  
  // if tail are different, there is no intersection
  if (firstProps.tail != secondProps.tail) return nullptr;
  
  // node this
  Node* longerList = firstProps.size < secondProps.size? second : first;
  Node* smallerList = firstProps.size < secondProps.size? first : second;
  
  int sizeDiff = abs(firstProps.size - secondProps.size);
  
  longerList = advanceToKth(longerList, sizeDiff);
  
  // better approach than != nullpointer
  while (longerList != smallerList) {
    longerList = longerList->next();
    smallerList = smallerList->next();
  }
  
  return longerList;
}

void test() {
  
  Node* t = new Node{3, nullptr};
  Node* t3 = new Node{2, nullptr};
  Node* t15 = new Node{12, nullptr};
  Node* t4 = new Node{4, nullptr};
  Node* t5 = new Node{5, nullptr};
  Node* t6 = new Node{1, nullptr};
  Node* t7 = new Node{8, nullptr};
  Node* t8 = new Node{10, nullptr};
  Node* t9 = new Node{11, nullptr};
  
  t->set_next(t3);
  t3->set_next(t15);
  t15->set_next(t6);
  
  
  t4->set_next(t5);
  t5->set_next(t6);
  
  t6->set_next(t7);
  t7->set_next(t8);
  t8->set_next(t9);
  
  Node* intersect = getIntersection(t, t4);
  //Node* intersect2 = getIntersection(t, t7);


  cout << "Should output: " << intersect->value() << endl;
  //cout << "Should output false: " << (intersect2 != nullptr) << endl;
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
