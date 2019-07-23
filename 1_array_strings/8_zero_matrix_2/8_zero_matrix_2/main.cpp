//
//  main.cpp
//  8_zero_matrix
//
//  Created by Gustavo Fonseca on 19/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Check if element in MxN matrix is 0, its entire row and column are set to 0
//  input: MxN matrix
//  output: MxN matrix with 0 columns and rows that elements were zero
//  This approach has O(1) for space

#include <iostream>
#include <vector>

using namespace std;


void nullifyRow(vector<vector<int>>& matrix, int row) {
  for(unsigned j = 0; j < matrix[0].size(); j++){
    matrix[row][j] = 0;
  }
}

void nullifyColumn(vector<vector<int>>& matrix, int column) {
  for(unsigned i = 0; i < matrix.size(); i++){
    matrix[i][column] = 0;
  }
}

bool setZeros(vector<vector<int>>& matrix) {
  
  if (matrix.size() == 0) return false;
  
  bool firstColumnHasZero = false;
  bool firstRowHasZero = false;
  
  // look for zero on first row
  for (unsigned i = 0; i < matrix[0].size(); i++) {
    if (matrix[0][i] == 0) {
      firstRowHasZero = true;
      break;
    }
  }
  
  // look for zero on first column
  for (unsigned i = 0; i < matrix.size(); i++) {
    if (matrix[i][0] == 0) {
      firstColumnHasZero = true;
      break;
    }
  }
  
  // look for zero in the rest of matrix
  for (unsigned i = 1; i < matrix.size(); i++) {
    for (unsigned j = 1; j < matrix[i].size(); j++) {
      if (matrix[i][j] == 0) {
        // mark row
        matrix[i][0] = 0;
        // mark column
        matrix[0][j] = 0;
      }
    }
  }
  
  // set zeros columns
  for (unsigned j = 0; j < matrix[0].size(); j++) {
    if (matrix[0][j] == 0) {
      nullifyColumn(matrix, j);
    }
  }
  
  // set zeros rows
  for (unsigned i = 0; i < matrix.size(); i++) {
    if (matrix[i][0] == 0) {
      nullifyRow(matrix, i);
    }
  }
  
  if (firstColumnHasZero) {
    for (unsigned i = 0; i < matrix.size(); i++) {
      matrix[i][0] = 0;
    }
  }

  if (firstRowHasZero) {
    for (unsigned j = 0; j < matrix[0].size(); j++) {
      matrix[0][j] = 0;
    }
  }
  
  return true;
}

void outputMatrix(const vector<vector<int> >& matrix) {
  
  for (unsigned i = 0; i < matrix.size(); i++) {
    
    for (unsigned j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << ' ';
    }
    cout << "\n";
  }
}

void test() {
  
  vector<vector<int>> m {{1, 2, 3, 7},
                         {5, 2, 0, 9},
                         {4, 0, 5, 4},
                         {3, 1, 6, 4}
  };
  
  setZeros(m);
  outputMatrix(m);
}

int main(int argc, const char * argv[]) {
  
  test();
  return 0;
}

