//
//  main.cpp
//  1_stacks_array
//
//  Created by Gustavo Fonseca on 05/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  How to implement 3 stacks in one vector

//  Stack: peak()

#include <iostream>
#include <exception>
#include <vector>

using namespace std;

class InvalidStackException : public exception {
  virtual const char* what() const throw() {
    return "Invalid stack";
  }
};

class FullStackException : public exception {
  virtual const char* what() const throw() {
    return "Maximum capacity reached";
  }
};

class EmptyStackException : public exception {
  virtual const char* what() const throw() {
    return "Index out of range";
  }
};

struct StackInfo {
public:
  int num;
  int size;
  int capacity;
  StackInfo(int n, int cp) : num(n), capacity(cp) {};
};

class MultiStack {
private:
  int capacity;
  int* items;
  vector<StackInfo*> stacks;
  int indexOfTop(int num);
public:
  MultiStack(int cap, int totalStacks);
  ~MultiStack();
  bool isValidStack(int stackNum);
  void push(int stackNum, int value);
  void pop(int stackNum);
  void output(int stackNum);
};

MultiStack::MultiStack(int cap, int totalStacks) : capacity(cap)
{
  int capacityPerStack = cap/totalStacks;
  for (int i = 0; i < totalStacks; i++) {
    stacks.push_back(new StackInfo{i, capacityPerStack});
  }
  
  items = new int[cap];
}

MultiStack::~MultiStack() {
  delete[] items;
}

int MultiStack::indexOfTop(int num) {
  StackInfo* currStack = stacks[num];
  int top = currStack->capacity * num + currStack->size - 1;
  return top;
}

bool MultiStack::isValidStack(int stackNum) {
  return stackNum >= 0 && stackNum < stacks.size();
}

void MultiStack::push(int stackNum, int value) {
  
  if (!isValidStack(stackNum)) {
    throw InvalidStackException();
  }
  
  // todo full stack
  StackInfo* currStack = stacks[stackNum];
  currStack->size++;
  items[indexOfTop(stackNum)] = value;
}

void MultiStack::pop(int stackNum) {
  
  if (!isValidStack(stackNum)) {
    throw InvalidStackException();
  }
  
  StackInfo* currStack = stacks[stackNum];
  
  if (currStack->size == 0) {
    throw EmptyStackException();
  }
  
  items[topOfstack(stackNum)] = 0;
  currStack->size--;
}

void MultiStack::output(int stackNum) {
  StackInfo* currStack = stacks[stackNum];
  int size = currStack->size;
  int topOfStack = indexOfTop(stackNum);
  
  for (int i = 0; i < size; i++) {
    cout << items[indexOfTop - i] << endl;
  }
  
}

int main(int argc, const char * argv[]) {
  MultiStack ms {9, 3};
  ms.push(1, 4);
  ms.push(1, 3);
  
  ms.push(2, 9);
  ms.push(2, 12);
  
  ms.output(2);
  
  //ms.pop(3);
  
  return 0;
}
