//
//  main.cpp
//  1_route_between_nodes
//
//  Created by Gustavo Fonseca on 19/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Check if there is a path between 2 nodes

#include <iostream>
#include <list>
#include <queue>

using namespace std;

enum class State { Unvisited, Visiting, Visited };

struct Node {
  string name;
  list<Node*> children;
  State state;
  explicit Node(string n) : name(n) {}
};

struct Graph {
  list<Node*> nodes;
  
  //~Graph() { delete nodes; }
};



bool hasPath(Graph g, Node* a, Node* b) {
  if (a == nullptr || b == nullptr) {
    return false;
  }
  
  if (a == b) {
    return true;
  }

  queue<Node*> queue;
  
  // set visited to false
  for (Node* node : g.nodes) {
    node->state = State::Unvisited;
  }
  
  a->state = State::Visiting;
  queue.push(a);
  Node* node;
  while (!queue.empty()) {
    // remove from queue
    node = queue.front();
    queue.pop();
    
    if (node != nullptr) {
      for (Node* adjecent : node->children) {
        if (adjecent->state == State::Unvisited) {
          if (adjecent == b) {
            return true;
          }
          else {
            node->state = State::Visiting;
            queue.push(adjecent);
          }
        }
      }
      node->state = State::Visited;
    }
  }
  
  return false;
}

int main(int argc, const char * argv[]) {
  Graph g;
  Node* p = new Node("Pai");
  Node* m = new Node("Mae");
  Node* o = new Node("Guto");
  Node* c = new Node("Carol");
  
  
  p->children.push_back(o);
  p->children.push_back(m);
  
  g.nodes.push_back(p);
  g.nodes.push_back(c);
  
  cout << hasPath(g, p, o) << endl;
  
  return 0;
}

