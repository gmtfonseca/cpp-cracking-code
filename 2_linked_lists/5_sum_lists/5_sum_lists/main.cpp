//
//  main.cpp
//  5_sum_lists
//
//  Created by Gustavo Fonseca on 29/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Sum two linked list stored in reverse order
//  Two linked list

#include <iostream>
#include <math.h>
#include "../../extra/linked_list.hpp"

using namespace std;

// 123 (321)
// 329 (923)

// elegant approach with O(n) space and O(n)
Node* sumListsBook(Node* list1,Node* list2, int carry) {
  
  if (list1 == nullptr && list2 == nullptr && carry == 0) return nullptr;
  
  Node* result = nullptr;
  
  int value = carry;
  
  if (list1 != nullptr) {
    value += list1->value();
  }
  
  if (list2 != nullptr) {
    value += list2->value();
  }
  
  result = new Node(value % 10, nullptr);
  
  if (list1 != nullptr || list2 || nullptr) {
    Node* more = sumListsBook(list1 == nullptr? nullptr : list1->next(),
                              list2 == nullptr? nullptr : list2->next(),
                              value >= 10? 1 : 0);
    result->set_next(more);
  }
  
  return result;
}

int listToNumber(Node* n);
Node* numberToList(int n);

Node* sumLists(Node* n1, Node* n2) {
  
  int sum = listToNumber(n1) + listToNumber(n2);
  
  return numberToList(sum);
}

// improve this
Node* numberToListReversed(int n) {
  Node* head = nullptr;
  Node* tail = nullptr;

  while (n > 0) {
    
    int digit = n % 10;
    n = n / 10;
    
    if (head == nullptr) {
      head = new Node(digit, nullptr);
    } else {
      if (tail == nullptr) {
        head->set_next(new Node(digit, nullptr));
        tail = head->next();
      } else {
        Node* newTail = new Node(digit, nullptr);
        tail->set_next(newTail);
        tail = newTail;
      }
    }
  }
  
  return head;
}

Node* numberToList(int n) {
  Node* head = nullptr;
  while (n > 0) {
    
    int digit = n % 10;
    n = n / 10;
    
    if (head == nullptr) {
      head = new Node(digit, nullptr);
    } else {
      Node* temp = head;
      head = new Node(digit, nullptr);
      head->set_next(temp);
    }
  }
  
  return head;
}

int listToNumber(Node* n) {
  
  if (n == nullptr) return 0;
  
  Node* curr = n;
  int index = 0;
  int result = 0;
  while (curr != nullptr) {
    result += curr->value() * pow(10, index);
    index++;
    curr = curr->next();
  }
  
  return result;
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
  Node* t4 = new Node{3, nullptr};
  

  Node* t5 = new Node{3, nullptr};
  Node* t6 = new Node{2, nullptr};
  Node* t7 = new Node{9, nullptr};

  t->set_next(t3);
  t3->set_next(t4);
  
  t5->set_next(t6);
  t6->set_next(t7);
  
  //Node* sum = sumLists(t, t5);
  Node* sum = sumListsBook(t, t5, 0);
  output(sum);
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
