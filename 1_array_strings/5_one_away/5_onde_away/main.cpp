//
//  main.cpp

//  5_onde_away
//
//  Created by Gustavo Fonseca on 16/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  insert, delete, update 1 char allowed
//  check if its one edit away from being the second string
//  input: 2 strings
//  output: boolean
//  edit <= 1 = true
//  Big O = O(N)

//  doubts? should I check for uppercase?

#include <iostream>
#include <cmath>

using namespace std;


bool isOneAway(string a, string b) {
  
  if (abs(int(a.length() - b.length())) > 1) return false;
  
  unsigned editCount = 0;
  unsigned j = 0;
  
  // iterate string
  for (unsigned i = 0; i < a.length(); i++) {
    
    // check for different character
    if (a[i] != b[j]) {
      
      // insertion
      if (a[i+1] == b[j]) {
        i++;
        j++;
        editCount++;
      }
      // delete
      else if (a[i] == b[j+1]) {
        j += 2;
        editCount++;
      }
      // edit
      else if (a[i+1] == b[j+1]) {
        j++;
        editCount++;
      }
    }
    else {
      j++;
    }
    
    if (editCount > 1) return false;
  
  }
  
  return true;
}


bool oneEditAway(const string& first, const string& second) {
  
  if (abs(int(first.length() - second.length())) > 1) {
    return false;
  }
  
  string shorter = first.length() < second.length()? first : second;
  string longer = first.length() < second.length()? second : first;
  
  unsigned idxShorter = 0, idxLonger = 0;
  bool foundDifference = false;
  
  while (idxShorter < first.length() && idxLonger < second.length()) {
    
    if (shorter[idxShorter] != longer[idxLonger]) {
      // can only find one difference
      if (foundDifference) return false;
      
      foundDifference = true;
      
      // only move the shorter string forward, when different, when they have the same length
      if (first.length() == second.length()) {
        idxShorter++;
      }
    } else {
      idxShorter++;
    }
          
    idxLonger++;
  }
  
  return true;
}

void test() {
  cout << "Should return true: " << isOneAway("pale", "ple") << endl;
  cout << "BShould return true: " << oneEditAway("pale", "ple") << endl;
  
  cout << "Should return true: " << isOneAway("pale", "psale") << endl;
  cout << "BShould return true: " << oneEditAway("pale", "psale") << endl;
  
  cout << "Should return true: " << isOneAway("pale", "bale") << endl;
  cout << "BShould return true: " << oneEditAway("pale", "bale") << endl;
  
  cout << "Should return false: " << isOneAway("pale", "bake") << endl;
  cout << "BShould return false: " << oneEditAway("pllse", "pale") << endl;
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
