//
//  main.cpp
//  2_callcenter
//
//  Created by Gustavo Fonseca on 01/06/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Three levels Employee: Respondent, Manager, Director
//  Dispatch call


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class Task {
  Business, Management, Service, Whatever
};

class Employee {
protected:
  vector<Task> tasks;
  Employee* superior;
  Employee(Employee* sup = nullptr) : superior{sup} {};
  bool canHandle(Task t) {
    return find(tasks.begin(), tasks.end(), t) != tasks.end();
  };
  virtual void handleCall(Task) = 0;
public:
  void dispatchCall(Task t) {
    if (!canHandle(t)) {
      if (superior != nullptr) {
        superior->dispatchCall(t);
      } else {
        cout << "No one can respond the call" << endl;
      }
    } else {
      handleCall(t);
    }
  };
};

class Director : public Employee {
public:
  Director() {
    tasks.push_back(Task::Business);
  }
  
  void handleCall(Task t) {
    cout << "Director answer" << endl;
  }
};

class Manager : public Employee {
public:
  Manager(Director* d) : Employee(d) {
    tasks.push_back(Task::Management);
  }
  
  void handleCall(Task t) {
    cout << "Manager answer" << endl;
  }
};

class Respondent : public Employee {
public:
  Respondent(Manager* m) : Employee(m) {
    // initialize tasks
    tasks.push_back(Task::Service);
  }
  
  void handleCall(Task t) {
    cout << "Respondent answer" << endl;
  }
};

int main(int argc, const char * argv[]) {
  
  Director* d = new Director();
  Manager* m = new Manager(d);
  Respondent* r = new Respondent(m);
  
  r->dispatchCall(Task::Whatever);
  
  return 0;
}
