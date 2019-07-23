//
//  main.cpp
//  2_permutation
//
//  Created by Gustavo Fonseca on 13/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.
//

// write method to decide if one of two given strings is a permutation of the other
// input: string a, b
// output: boolean


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


bool is_equal(string a, string b) {
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  return a == b;
}


bool is_permutation(string a, string b) {
  if (a == b) return true;
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  return a == b;
}

// how many of b is in a
unsigned count_permutations(const string& a, const string& b) {
  
  if (a == b) return true;
  
  unsigned count = 0;
  string curr = "";
  
  for (unsigned i = 0; i < a.length(); i ++) {
    curr = a.substr(i, b.length());
    if (is_equal(curr, b)) {
      count++;
    }
  }
  
  return count;
}

bool is_permutation_optimal(string a, string b) {
  
  if (a.length() != b.length()) return false;
  
  vector<int> chars(128);
  
  for (char ch : a) {
    chars[ch]++;
  }
  
  for (char ch: b) {
    
    chars[ch]--;
    
    if (chars[ch] < 0) {
      return false;
    }
  }
  
  return true;

}

void test() {
  cout << "Should return 1: " << count_permutations("bacd", "ab") << endl;
  cout << "Should return 0: " << count_permutations("acde", "af") << endl;
  
  cout << "Is Should return 1: " << is_permutation("abbbc", "cabbb") << endl;
  cout << "Is Should return 0: " << is_permutation("degef", "efgea") << endl;
  
  cout << "Optimal Should return 1: " << is_permutation("abbbaaapc", "aacabbbpa") << endl;
  cout << "Optimal Should return 0: " << is_permutation("degef", "efgea") << endl;
}
                    
int main(int argc, const char * argv[]) {
  test();
  
  return 0;
}
