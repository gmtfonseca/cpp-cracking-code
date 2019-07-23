//
//  main.cpp
//  6_animal_shelter
//
//  Created by Gustavo Fonseca on 14/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  Create a Data Strucute to hold an animal shelter

#include <iostream>
#include <list>

using namespace std;

// structures that will be holded by the shelter
struct Animal {
protected:
  string n;
  char t;
public:
  Animal(string name, char type) : n(name), t(type) {}
  string name() const { return n; }
  char type() const { return t; }
};

struct Dog : Animal {
  Dog(string n) : Animal(n, 'D') {}
};

struct Cat : Animal {
  Cat(string n) : Animal(n, 'C') {}
};

class EmptyShelterException {};

class AnimalShelter {
private:
  list<Animal*> shelter;
  int size;
public:
  
  void enqueue(Animal* a) {
    shelter.push_back(a);
  }
  
  Animal* dequeue() {
    if (shelter.empty()) throw EmptyShelterException();
    
    Animal* temp = shelter.front();
    shelter.pop_front();
    return temp;
  }
  
  Animal* dequeue(char type) {
    if (shelter.empty()) throw EmptyShelterException();
    
    Animal* front = nullptr;
    for (list<Animal*>::const_iterator it = shelter.begin(); it != shelter.end(); it++) {
      if ((*it)->type() == type) {
        front = *it;
        shelter.erase(it);
        break;
      }
    }
    return front;
  }
  
  void output() {
    for (const auto& animal : shelter) {
      cout << animal->name() << endl;
    }
  }
  
};

int main(int argc, const char * argv[]) {

  Dog* d = new Dog{"Tony"};
  Dog* d1 = new Dog{"Biba"};
  Dog* d2 = new Dog{"Tuque"};
  Dog* d3 = new Dog{"Pepa"};
  
  Cat* c1 = new Cat{"Mimi"};
  Cat* c2 = new Cat{"Mimuxo"};
  Cat* c3 = new Cat{"Mimoso"};
  
  AnimalShelter shelter;
  shelter.enqueue(d);
  shelter.enqueue(d1);
  shelter.enqueue(c1);
  shelter.enqueue(d2);
  shelter.enqueue(c2);
  shelter.enqueue(c3);
  shelter.enqueue(d3);
  
  cout << shelter.dequeue('C')->name() << endl;
  cout << shelter.dequeue('D')->name() << endl;
  cout << shelter.dequeue('D')->name() << endl;
  
  shelter.output();
  
  // tony -> biba -> mimi -> tuque -> mimuxo -> mimoso -> pepa
  // tony -> biba -> tuque -> pepa
  // mimi -> mimuxo -> mimoso
  
  
  return 0;
}
