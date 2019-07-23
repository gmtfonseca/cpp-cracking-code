//
//  main.cpp
//  6_palindrome
//
//  Created by Gustavo Fonseca on 30/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//
//  check if linked list is palindrome
//  Input: linked list
//  Output: bool

#include <iostream>
#include "../../extra/linked_list.hpp"
#include <stack>

using namespace std;

// my favourite approach
bool isPalindromeStack(Node* head) {
  stack<Node*> half;
  
  Node* slow = head;
  Node* fast = head;
  
  // puts first half into stack
  while (fast != nullptr && fast->next() != nullptr) {
    half.push(slow);
    slow = slow->next();
    fast = fast->next()->next();
  }
  
  // takes care of possibly middle character
  // A B C D C B A - ODD
  // A B C C B A - Even
  if (fast != nullptr) {
    slow = slow->next();
  }
  
  // A R A R A
  while (slow != nullptr) {
    string ch = half.top()->value();
    half.pop();
    
    if (ch != slow->value()) {
      return false;
    }
    
    slow = slow->next();
  }
  
  return true;
}

string toStr(Node* n) {
  Node* curr = n;
  string result;
  
  while (curr != nullptr) {
    result += curr->value();
    curr = curr->next();
  }
  
  return result;
}

Node* reverseAndClone(Node* n) {
  Node* head = nullptr;
  
  while (n != nullptr) {
    Node* clone = new Node(n->value(), nullptr);
    clone->set_next(head);
    head = clone;
    n = n->next();
  }
  return head;
}



// this does not compare only the first half
bool isEqual(Node* one, Node* two) {
  while (one != nullptr && two != nullptr) {
    if (one->value() != two->value()) {
      return false;
    }
    one = one->next();
    two = two->next();
  }
  // guarantee that are the same length
  return one == nullptr && two == nullptr;
}

// former recursive approach
string toReversedStr(Node* n) {
  if (n == nullptr) return "";
  
  string result = toReversedStr(n->next());
  
  result += n->value();
  
  return result;
}

// ARARA
bool isPalindrome(Node* n) {
  Node* reversedClone = reverseAndClone(n);
  
  return isEqual(n, reversedClone);
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
  Node* t = new Node{"A", nullptr};
  Node* t3 = new Node{"R", nullptr};
  Node* t4 = new Node{"A", nullptr};
  Node* t5 = new Node{"R", nullptr};
  Node* t6 = new Node{"B", nullptr};

  
  t->set_next(t3);
  t3->set_next(t4);
  t4->set_next(t5);
  t5->set_next(t6);
  
  cout << "Should output true: " << isPalindrome(t) << endl;
  cout << "Should output true: " << isPalindromeStack(t) << endl;
  
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
