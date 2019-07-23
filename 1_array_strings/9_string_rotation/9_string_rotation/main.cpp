//
//  main.cpp
//  9_string_rotation
//
//  Created by Gustavo Fonseca on 20/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//  check if s2 is rotation of s1
//  helper function: isSubstring
//  only one call

#include <iostream>
#include <algorithm>

using namespace std;

bool isSubstring(const string& str, const string& substr) {
  for (unsigned i = 0; i < str.length(); i++) {
    if (str[i] == substr[0]) {
      
      int idx1 = i+1;
      int idx2 = 1;
      
      while (idx1 < str.length() && idx2 < substr.length()) {
        if (str[idx1] != substr[idx2]) {
          break;
        }
        
        if (idx2 == (substr.length() - 1)) return true;
        
        idx1++;
        idx2++;
      }
    }
  }
  
  return false;
}

void testSubstring() {
  cout << "Should return true: " << isSubstring("carroverde", "carro") << endl;
  cout << "Should return true: " << isSubstring("novo", "ovo") << endl;
  cout << "Should return true: " << isSubstring("patinete", "tine") << endl;
  cout << "Should return false: " << isSubstring("marcelino", "marcia") << endl;
  cout << "Should return true: " << isSubstring("aaaaaovoaasss", "aaovo") << endl;
}

// waterbottle
// erbottlewat

bool isRotation(string str1, string str2) {
  
  if (str1.length() != str2.length()) return false;
  
  return isSubstring(str2 + str2, str1);
}

void testStringRotation() {
  cout << "Should return true: " << isRotation("waterbottle","erbottlewat") << endl;
  cout << "Should return true: " << isRotation("waterbottle","bottlewater") << endl;
  cout << "Should return false: " << isRotation("waterbottle","erbottlawat") << endl;
}

int main(int argc, const char * argv[]) {
  testStringRotation();
  return 0;
}
