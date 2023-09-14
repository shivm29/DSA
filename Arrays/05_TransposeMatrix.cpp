#include <iostream>
using namespace std;

int main() {

  /*
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16

    7 4 1
    8 5 2
    9 6 3
  */

  int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  for(int i = 0; i < 3; i++) {
    for(int j = i; j < 3; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  

  return 0;
}