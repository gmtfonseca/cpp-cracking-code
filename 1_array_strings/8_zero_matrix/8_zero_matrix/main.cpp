//
//  main.cpp
//  8_zero_matrix
//
//  Created by Gustavo Fonseca on 19/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  Check if element in MxN matrix is 0, its entire row and column are set to 0
//  input: MxN matrix
//  output: MxN matrix with 0 columns and rows that elements were zero
//  TODO: duplicated columns and rows?
//  R * M + N * C + N * M = (RM + NC + NM)

#include <iostream>
#include <vector>

using namespace std;


void nullifyRows(vector<vector<int>>& matrix, vector<int> rows) {
  for (unsigned i = 0; i < rows.size(); i++) {
    for (unsigned j = 0; j < matrix[rows[i]].size(); j++) {
      matrix[rows[i]][j] = 0;
    }
  }
}

// N * C
void nullifyColumns(vector<vector<int>>& matrix, vector<int> columns) {
  // zero columns
  for (unsigned i = 0; i < matrix.size(); i++) {
    for (unsigned j = 0; j < columns.size(); j++) {
      
      if (columns[j] < matrix[i].size()) {
        matrix[i][columns[j]] = 0;
      }
      
    }
  }
}


bool setZerosMatrix(vector<vector<int>>& matrix) {
  
  if (matrix.size() == 0) return false;
  
  
  vector<int> columns;
  vector<int> rows;
  
  // N * M
  for (unsigned i = 0; i < matrix.size(); i++) {
    for (unsigned j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] == 0) {
        rows.push_back(i);
        columns.push_back(j);
      }
    }
  }
  
  nullifyRows(matrix, rows);
  nullifyColumns(matrix, columns);

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
  
  vector<vector<int>> m {{1, 2, 3},
                         {5, 2, 0, 9},
                         {4, 0},
                         {3, 1, 6, 2}
                        };
  
  // expected output
  /* 1, 0, 0
     0, 0, 0, 0
     0, 0
     3, 0, 0, 2
   */
  setZerosMatrix(m);
  outputMatrix(m);
}

int main(int argc, const char * argv[]) {
  
  test();
  return 0;
}
