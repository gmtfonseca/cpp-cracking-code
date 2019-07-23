//
//  main.cpp
//  2_stack_min
//
//  Created by Gustavo Fonseca on 10/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  add function min(), operating in O(1) time
//  O(1) time, but O(n) space

#include <iostream>
#include <stack>

using namespace std;

class EmptyStackException {
  
};

// example
/*
 2 -> 2          min: 2
 3 -> 2 3        min: 2
 5 -> 2 3 5      min: 2
 1 -> 2 3 5 0    min: 1
 6 -> 2 3 5 0 6  min: 1
 */

class StackMinOptimized {
  stack<int> items;
  int min;
public:
  int top() {
    if (items.empty()) {
      throw EmptyStackException();
    }
    int t = items.top();
    if (t < min) {
      t = min;
    }
    return t;
  }
  
  void push(int item) {
    int newItem = item;
    
    if (items.empty() || item < min) {
      newItem = 2 * item - min;
      min = item;
    }
    
    items.push(newItem);
  }
  
  int pop() {
    
    if (items.empty()) {
      throw EmptyStackException();
    }
    
    int top = items.top();
    items.pop();
    
    if (top < min) {
      min = 2 * min - top;
    }
    
    return top;
  }
  
  int getMin() {
    return min;
  }
};


template<typename T>
class StackMin {
  stack<T> items;
  stack<T> min;
public:
  T top() {
    if (items.empty()) {
      throw EmptyStackException();
    }
    
    return items.top();
  }
  
  void push(T item) {
    if (min.empty() || item < min.top()) {
      min.push(item);
    }
    
    items.push(item);
  }
  
  void pop() {
    
    if (items.empty()) {
      throw EmptyStackException();
    }
    
    if (items.top() == min.top()) {
      min.pop();
    }
    
    items.pop();
  }
  
  T getMin() {
    if (items.empty()) {
      throw EmptyStackException();
    }
    
    return min.top();
  }
  
};

int main(int argc, const char * argv[]) {
  StackMinOptimized a;
  a.push(3);
  a.push(4);
  a.push(2);
  a.push(4);
  a.push(1);
  
  cout << a.top() << endl;
  return 0;
}
