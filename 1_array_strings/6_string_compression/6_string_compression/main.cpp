//
//  main.cpp
//  6_string_compression
//
//  Created by Gustavo Fonseca on 17/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  Basic string compression, counting the letters
//  Input: string
//  Output: compressed string
//  BIG O: O(1)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// first attempt
string getCompressedOld(string value) {
  
  sort(value.begin(), value.end());
  
  string compressedValue;
  char lastChar = ' ';
  unsigned charCount = 0;
  
  for (unsigned i = 0; i < value.length(); i++) {
    
    
    if (value[i+1] != value[i]) {
      charCount++;
      compressedValue.append(to_string(charCount));
      charCount = 0;
    }
    else if (value[i] != lastChar) {
      compressedValue.append(1, value[i]);
      charCount++;
      lastChar = value[i];
      
    } else {
      charCount++;
    }
  }
  
  return compressedValue.length() < value.length()? compressedValue : value;
}


vector<int> getFrequencyCollection(const string& value) {
  
  // ASCII table
  vector<int> collection (('z' - 'A') + 1);
  
  // O(n)
  for (char ch : value) {
    if (ch != ' ') collection[ch - 'A']++;
  }
  
  return collection;
}

char getCharacterValue(int i) {
  return char(i + 'A');
}

string buildCompressedString(vector<int> collection) {
  
  string compressedValue;
  
  // O(1) + O(n) = O(n)
  for (unsigned i = 0; i < collection.size(); i++) {
    
    if (collection[i] != 0) {
      
      compressedValue += getCharacterValue(i);
      
      if (collection[i] > 1) {
        compressedValue += to_string(collection[i]);;
      }
    }
  }
  
  return compressedValue;
}

string getCompressedString(const string& value) {
  
  string compressedString = buildCompressedString(getFrequencyCollection(value));
  
  if (compressedString.length() >= value.length()) {
    compressedString = value;
  }
  
  return compressedString;
}

// book implementation - ordered assumption
string getCompressedBook(const string& str) {
  
  string compressedString;
  int countConsecutive = 0;
  
  for (unsigned i = 0; i < str.length(); i++) {
    
    countConsecutive++;
    
    if (str[i] != str[i+1] || (i == (str.length() - 1))) {
      compressedString += str[i] + to_string(countConsecutive);
      countConsecutive = 0;
    }
      
  }
  
  return compressedString.length() >= str.length()? str : compressedString;
}

void test() {
  cout << "Should return a3b2c4: " << getCompressedString("aaabbcccc") << endl;
  cout << "Should return a3b2c4: " << getCompressedBook("aaabbcccc") << endl;
  
  cout << "Should return ?: " << getCompressedString("pppppcccddddcccpppPPPDDD") << endl;
  cout << "Should return abc4: " << getCompressedString("abcccc") << endl;
  cout << "Should return AZ3a3z2: " << getCompressedString("AZZZazaaz") << endl;
}

int main(int argc, const char * argv[]) {
  
  test();
  
  return 0;
}
