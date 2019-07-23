//
//  main.cpp
//  5_sort_stack
//
//  Created by Gustavo Fonseca on 13/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

void sort(stack<int>& s) {
  
  stack<int> sorted;
  
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    
    // locates the proper place to put it
    while (!sorted.empty() && sorted.top() > top) {
      // put element in the first
      s.push(sorted.top());
      sorted.pop();
    }

    // insert element in the right spot
    sorted.push(top);
  }
  
  // reverese it
  while (!sorted.empty()) {
    s.push(sorted.top());
    sorted.pop();
  }
}


int main(int argc, const char * argv[]) {
  
  stack<int> s;
  s.push(4);
  s.push(3);
  s.push(9);
  s.push(6);
  s.push(1);
  
  sort(s);
  
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
  
  return 0;
}
