//
//  main.cpp
//  3_set_of_stacks
//
//  Created by Gustavo Fonseca on 12/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  TODO: SetOfStacks
//  When it reachs capacity, creates a new stack
//  push, pop should behave like it was just a single stack

#include <iostream>
#include <stack>
#include <vector>

// ways of implement stack - linked list, array of pointers

// RAII
using namespace std;

class EmptyStackException {};


class Test {
public:
  vector<stack<int>> stacks;
};

class SetOfStacks {
private:
  int capacity;
  vector<stack<int>*> stacks;
  
  stack<int>* getLastStack() {
    return stacks[static_cast<int>(stacks.size() - 1)];
  }
public:
  SetOfStacks(int cap) : capacity(cap) {
    // initialize first stack
    stack<int>* newStack = new stack<int>;
    stacks.push_back(newStack);
  }
  
  ~SetOfStacks() {
    for (auto stack : stacks) {
      delete stack;
    }
  }
  
  void push(int v) {
    auto lastStack = getLastStack();
    
    lastStack->push(v);
    
    // stack reach max capacity
    if (lastStack->size() == capacity) {
      stack<int>* newStack = new stack<int>;
      stacks.push_back(newStack);
    }
  }
  
  int pop() {
    if (stacks.empty()) {
      throw EmptyStackException();
    }
    
    auto lastStack = getLastStack();
    int top = lastStack->top();
    lastStack->pop();
    
    if (lastStack->empty()) {
      stack<int>* temp = lastStack;
      stacks.pop_back();
      delete temp;
    }
    
    return top;
  }
  
  // FOLLOW-UP
  int popAt(int index) {
    if (stacks[index]->empty()) {
      throw EmptyStackException();
    }
    
    int top = stacks[index]->top();
    stacks[index]->pop();
    
    // if empty, remove stack from stacks
    if (stacks[index]->empty()) {
      stack<int>* temp = stacks[index];
      stacks.erase(stacks.begin() + index);
      delete temp;
    }
    
    return top;
  }
  
  int top() {
    if (stacks.empty()) {
      throw EmptyStackException();
    }
    
    return getLastStack()->top();
  }
  
};

int main(int argc, const char * argv[]) {
  SetOfStacks set {3};
  set.push(3);
  set.push(2);
  set.push(4);
  set.push(6);
  set.push(10);
  set.push(12);
  set.push(15);

  
  Test t;
  stack<int> s1;
  stack<int> s2;
  
  s1.push(5);
  t.stacks.push_back(s1);
  t.stacks.push_back(s2);
  cout << t.stacks[0].top() << endl;
  
  return 0;
}
