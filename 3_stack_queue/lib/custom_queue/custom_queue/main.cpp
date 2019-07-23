//
//  main.cpp
//  custom_queue
//
//  Created by Gustavo Fonseca on 03/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  Custom implementation of queue

//  Ordering: FIFO

#include <iostream>
#include <exception>

using namespace std;

class EmptyQueue : public exception {
  virtual const char* what() const throw()
  {
    return "Empty queue";
  }
};

template <typename T>
class Queue {
private:
  struct QueueNode {
    T data;
    QueueNode* next;
    QueueNode(T dta, QueueNode* nxt) : data(dta), next(nxt) {};
  };
  QueueNode* f;
  QueueNode* b;
public:
  void add(T data);
  void remove();
  T front() { return f; }
  T back() { return b; }
  bool isEmpty();
  void output();
  Queue() : f{nullptr}, b{nullptr} {};
  ~Queue();
};

template <typename T>
Queue<T>::~Queue() {
  while (f != nullptr) {
    this->remove();
  }
}

template <typename T>
bool Queue<T>::isEmpty() {
  return f == nullptr;
}

template <typename T>
void Queue<T>::add(T data) {
  QueueNode* node = new QueueNode(data, nullptr);
  if (b != nullptr) {
    b->next = node;
  }
  
  b = node;
  if (f == nullptr) {
    f = b;
  }
}

template <typename T>
void Queue<T>::remove() {
  if (f == nullptr) throw EmptyQueue();
  QueueNode* temp = f;
  f = f->next;
  
  if (f == nullptr) {
    b = nullptr;
  }
  delete temp;
}

template <typename T>
void Queue<T>::output() {
  QueueNode* curr = f;
  while (curr != nullptr) {
    cout << curr->data << " -> ";
    curr = curr->next;
  }
  cout << endl;
}

void test() {
  Queue<int> queue;
  queue.add(3);
  queue.add(2);
  queue.add(1);

  //queue.output();
}

int main(int argc, const char * argv[]) {
  
  test();
  cout << "End." << endl;
  
  return 0;
}
