//
//  main.cpp
//  1_is_unique
//
//  Created by Gustavo Fonseca on 12/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//

#include <iostream>
#include <vector>

// implement an algorithm to define if a given string has only unique characters,
// rule: without another data structure
// input: string
// output: bool

using namespace std;

// with recursion
bool only_unique(const string& s, unsigned int pos) {
  
  for (unsigned int i = 0; i < s.length(); i++) {
    if (s.at(pos) == s.at(i) && i != pos) {
      return false;
    }
  }
  
  if (pos < s.length() - 1) {
    return only_unique(s, pos + 1);
  }
  
  return true;
}

// without recursion
bool only_unique2(const string& s) {
  
  for (unsigned int i = 0; i < s.length(); i++) {
    for (unsigned int j = 0; j < s.length(); j++) {
      if (s[i] == s[j] && i != j) {
        return false;
      }
    }
  }
  
  return true;
  
}

// book implementation
bool is_unique(const string& s) {
  
  // pre condition
  if (s.length() > 128) return false;
  
  vector<bool> v(128);
  
  for (char ch : s) {
    
    if (v[ch]) {
      return false;
    }
    
    v[ch] = true;
    
  }
  return true;
}

// test cases
void test() {
  // should return false
  cout << "Should return false: " << only_unique("casa", 0) << endl;
  cout << "Should return false: " << only_unique2("casa") << endl;
  cout << "B Should return false: " << is_unique("casa") << endl;
  
  // should return false
  cout << "Should return false: " << only_unique("ovo", 0) << endl;
  cout << "Should return false: " << only_unique2("ovo") << endl;
  cout << "B Should return false: " << is_unique("ovo") << endl;
  
  // should return true
  cout << "Should return true: " << only_unique("caso", 0) << endl;
  cout << "Should return true: " << only_unique2("caso") << endl;
  cout << "B Should return true: " << is_unique("caso") << endl;
  
  // should return true
  cout << "Should return true: " << only_unique("nami", 0) << "\n";
  cout << "Should return true: " << only_unique2("nami") << "\n";
  cout << "B Should return true: " << is_unique("nami") << "\n";
  
  cout << "Should return true: " << only_unique("abcdefghijklmn", 0) << "\n";
  cout << "Should return true: " << only_unique2("abcdefghijklmn") << "\n";
  cout << "B Should return true: " << is_unique("abcdefghijklmn") << "\n";
}

int main(int argc, const char * argv[]) {
  
  test();
  
  return 0;
}
