//
//  linked_list.hpp
//  1_remove_dups
//
//  Created by Gustavo Fonseca on 26/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <stdio.h>

using namespace std;

struct Node {
private:
  int v;
  Node* n;
public:
  Node(int value, Node* next = nullptr) : v{value}, n{next} {}
  
  
  Node* next() { return n; };
  int value() const { return v; }
  void set_value(int value) { v = value; };
  void set_next(Node* next) { n =  next; }
};

#endif /* linked_list_hpp */
