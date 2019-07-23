//
//  main.cpp
//  4_palindrome_permutation
//
//  Created by Gustavo Fonseca on 14/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Check if a given string is a permutation of a palidrome
//  input: string
//  output: boolean
//  doubts: should I consider the case?
//          ASCII or Unicode?

#include <iostream>
#include <vector>

using namespace std;

// original solution
bool is_palindrome_perm(const string& s) {
  
  if (s.empty()) return false;
  
  vector<int> chars (128);
  
  for (char ch : s) {
    // insert character
    if (ch != ' ') {
      if (chars[ch]) {
        chars[ch]--;
      } else {
        chars[ch]++;
      }
    }
  }
  
  int count = 0;
  for (int i : chars) {
    if (i > 0) {
      count++;
    }
    
    if (count > 1) {
      return false;
    }
  }
  
  return true;
}

// book second solution
bool is_palindrome_perm_book(const string& s) {
  
  if (s.empty()) return false;
  
  vector<int> chars (128);
  
  int countOdd = 0;
  for (char ch : s) {
    // insert character
    if (ch != ' ') {
      chars[ch]++;
      
      // check if it is odd, the first ocurrance of a letter will be neutralized by its second, and only 1 remains
      if (chars[ch] % 2 == 1) {
        countOdd++;
      } else {
        countOdd--;
      }
    }
  }
  

  return countOdd <= 1;;
}

void test() {
  cout << "Should return true: " << is_palindrome_perm_book("voo") << endl;
  cout << "Should return true: " << is_palindrome_perm_book("tact coa") << endl;
  cout << "Should return true: " << is_palindrome_perm_book("hanah") << endl;
  cout << "Should return false: " << is_palindrome_perm_book("gato") << endl;
  cout << "Should return false: " << is_palindrome_perm_book("tes") << endl;
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
