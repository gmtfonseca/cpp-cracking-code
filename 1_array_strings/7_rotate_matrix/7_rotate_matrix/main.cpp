//
//  main.cpp
//  7_rotate_matrix
//
//  Created by Gustavo Fonseca on 18/04/18.
//  Copyright © 2018 Gustavo Fonseca. All rights reserved.

//  NxN matrix
//  each pixel = 4 bytes = 32 bits
//  rotate image 90 degres
//  doubts: Can I do it in place? Which direction?
//  extremely hard problem, took like 5 hours to understand it


#include <iostream>
#include <vector>

using namespace std;

// image
/* 1 2 3 4 x = 0
   5 6 7 8
   9 4 3 2
   4 5 6 9
 
 4
    1 2 3 1 x = 0
    5 6 7 8
    9 4 3 2
    9 5 6 4
 
   y = 0
*/

bool rotateImage(vector<vector<int> >& image) {
  
  int n = int(image.size());

  
  if (n != image[0].size()) return false;
  
  // goes through the layers - quantity of layers is equal the size/2
  for (unsigned x = 0; x < n / 2; x++) {
    
    for (unsigned y = x; y < n - x - 1; y++) {
      
      int temp = image[x][y];
      
      // bottom-left > top-left
      image[x][y] = image[n - y - 1][x];
      
      // bottom-right > bottom-left
      image[n - y - 1][x] = image[n - x - 1][n - y - 1];
      
      // top-right > bottom-right
      image[n - x - 1][n - y - 1] = image[y][n - x - 1];
      
      // top-left > top-right
      image[y][n - x - 1] = temp;
      
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

  vector<vector<int> > matrix {{1,2,3,4},
                                {5,6,7,8},
                                {9,4,3,2},
                                {3,5,4,7}
                                };
  
  
  outputMatrix(matrix);
  rotateImage(matrix);
  cout << "\n";
  outputMatrix(matrix);
  
  
}

int main(int argc, const char * argv[]) {
  
  test();
  
  return 0;
}
