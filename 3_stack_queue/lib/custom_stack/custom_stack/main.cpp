//
//  main.cpp
//  custom_stack
//
//  Created by Gustavo Fonseca on 03/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  Custom implementation of stack

//  Ordering: LIFO

#include <iostream>
#include <exception>

using namespace std;

class NullStack : public exception {
  virtual const char* what() const throw()
  {
    return "Null stack";
  }
};

template <typename T>
class Stack {
protected:
  struct StackNode {
    T data;
    StackNode* next;
    StackNode(T dta, StackNode* nxt) : data(dta), next(nxt) {};
    ~StackNode() { delete next; }
  };
  StackNode* top;
public:
  void insert(T data);
  StackNode* getMin() { return minimum->top->data;};
  void pop();
  T peak() { if (top == nullptr) throw new NullStack; return top->data; }
  bool isEmpty();
  void output();
  ~Stack();
};

template <typename T>
Stack<T>::~Stack() {

}

template <typename T>
void Stack<T>::insert(T data) {
  StackNode* node = new StackNode(data, top);
  

  
  top = node;
}

template <typename T>
void Stack<T>::pop() {
  if (top == nullptr) throw new NullStack;
  
  
  
  StackNode* temp = top;
  top = top->next;
  delete temp;
}

template <typename T>
void Stack<T>::output() {
  if (top == nullptr) throw new NullStack;
  
  StackNode* curr = top;
  while (curr != nullptr) {
    cout << curr->data << " -> ";
    curr = curr->next;
  }
  cout << endl;
}


template <typename T>
bool Stack<T>::isEmpty() {
  return top == nullptr;
}

void test() {
  Stack<int> stack;
  stack.insert(4);
  stack.insert(6);
  stack.insert(1);
  stack.insert(3);
  stack.insert(2);
  
  cout << stack.getMin()->data << endl;
}

int main(int argc, const char * argv[]) {

  test();
  return 0;
}
