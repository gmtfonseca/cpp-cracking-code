//
//  main.cpp
//  1_triple_step
//
//  Created by Gustavo Fonseca on 31/05/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  N steps staircase
//  1, 2, 3 steps at a time
//  how many possible ways

#include <iostream>
#include <vector>

using namespace std;

// 1 2 3 4 5 6 7 8 9
int countHops(int n, vector<int>& memo) {
  if (n < 0) {
    return 0;
  } else if (n == 0) {
    return 1;
  } else {
    if (memo[n] == 0) {
      memo[n] = countHops(n - 1, memo) + countHops(n - 2, memo) + countHops(n - 3, memo);
    }
    return memo[n];
  }
}

// bottom-up
int countHops_b(int n) {
  
  vector<int> memo(n);
  
  // 1 2 3 4 5 6
  memo[0] = 0;
  memo[1] = 1;
  memo[2] = 2;
  for (unsigned i = 3; i < n; i++) {
    memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
  }

  return memo[n - 1] + memo[n - 2] + memo[n - 3];
}

int countHops(int n) {
  vector<int> memo(n + 1);
  return countHops(n, memo);
}

int main(int argc, const char * argv[]) {
  // insert code here...
  cout << countHops_b(5) << endl;
  cout << "Correct: " << countHops(5) << endl;
  
  return 0;
}
