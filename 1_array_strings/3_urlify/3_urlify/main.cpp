//
//  main.cpp
//  3_urlify
//
//  Created by Gustavo Fonseca on 14/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Replace whitespaces with %20
//  assumptions: enough space at the end
//  have true length of the string
//  input: string with " "
//  output: string with %20

#include <iostream>

using namespace std;

string urlify(const string& s) {
  
  if (s.empty()) return "";
  
  string result = "";
  
  for (char ch : s) {
    if (ch == ' ') {
      result.append("%20");
    } else {
      result.append(1, ch);
    }
  }
  
  return result;
  
}

// book implementation without C++ append

// TEST: "TESTE DO GUSTAVO    "
void replaceSpaces(string s , unsigned trueLength) {
  
  unsigned spaceCount = 0;
  int index = 0;

  // count spaces
  for (unsigned i = 0; i < trueLength; i++) {
    if (s[i] == ' ') {
      spaceCount++;
    }
  }
  
  // get the end of the character array
  index = trueLength + (spaceCount * 2);
  
  // set end char stream  with C style termination
  //s[trueLength] = '\0';
  
  for (int i = (trueLength - 1); i >= 0; i--) {
    
    if (s[i] == ' ') {
      s[index - 1] = '0';
      s[index - 2] = '2';
      s[index - 3] = '%';
      index -= 3;
    }
    else {
      s[index - 1] = s[i];
      index--;
    }
  }
  
  cout << s << endl;
  
}

int main(int argc, const char * argv[]) {
  
  //cout << urlify("TESTE DO GUSTAVO") << "\n";
  
  replaceSpaces("TESTE DO GUSTAVO    ", 16);
  
  return 0;
}
