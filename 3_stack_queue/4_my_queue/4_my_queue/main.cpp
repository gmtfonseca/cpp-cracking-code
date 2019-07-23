//
//  main.cpp
//  4_my_queue
//
//  Created by Gustavo Fonseca on 13/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Implement a MyQueue class implementing a queue with 2 stacks
//  O(n) time on dequeue and front()
//  Cannot implement back() in this approach

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> ordered;
  stack<int> reversed;
  
  void shiftStack() {
    if (reversed.empty()) {
      while (!ordered.empty()) {
        reversed.push(ordered.top());
        ordered.pop();
      }
    }
  }
public:
  MyQueue() {}
  void enqueue(int v) {
    ordered.push(v);
  }
  
  int dequeue() {
    shiftStack();
    int first = reversed.top();
    reversed.pop();
    return first;
  }
  
  int front() {
    shiftStack();
    return reversed.top();
  }
  
};

int main(int argc, const char * argv[]) {

  MyQueue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  
  q.dequeue();
  cout << q.front() << endl;
  
  return 0;
}
