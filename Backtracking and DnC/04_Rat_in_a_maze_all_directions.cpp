#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Approach by babbar
// AMAZON | MICROSOFT
// VIMP



// returns true if the position is in bound
// returns true if the position is not visited yet
// returns true if the position's value is 1
bool isSafe(int maze[4][4], int row, int col, int srcx, int srcy, vector<vector<bool>> &visited) {
  // if(srcx >= 4 || srcx < 0 || srcy >= 4 || srcy < 0) return false;
  // if(maze[srcx][srcy] == 0) return false;
  // if(visited[srcx][srcy]) return false;

  if((srcx >= 0 && srcx < row) && (srcy >= 0 && srcy < col) && maze[srcx][srcy] == 1 && visited[srcx][srcy] == false) {
    return true;
  }

  return false;
}

void printWays(int maze[4][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited ){
    // base case : 
  if(row-1 == srcx && col-1 == srcy){
    // reached destination
    cout << output << endl;
    return;
  }

  // UP
  if(isSafe(maze, row, col, srcx-1, srcy, visited)){
    // mark visited
    visited[srcx-1][srcy] = true;
    output.push_back('U');
    printWays(maze, row, col, srcx-1, srcy, output, visited);
    output.pop_back();
    visited[srcx-1][srcy] = false;
  }
  // DOWN
  if(isSafe(maze, row, col, srcx+1, srcy, visited)){
    // mark visited
    visited[srcx+1][srcy] = true;
    output.push_back('D');
    printWays(maze, row, col, srcx+1, srcy, output, visited);
    output.pop_back();
    visited[srcx+1][srcy] = false;
  }
  // LEFT
  if(isSafe(maze, row, col, srcx, srcy-1, visited)){
    // mark visited
    visited[srcx][srcy-1] = true;
    output.push_back('L');
    printWays(maze, row, col, srcx, srcy-1, output, visited);
    output.pop_back();
    visited[srcx][srcy-1] = false;
  }
  // RIGHT
  if(isSafe(maze, row, col, srcx, srcy+1, visited)){
    // mark visited
    visited[srcx][srcy+1] = true;
    output.push_back('R');
    printWays(maze, row, col, srcx, srcy+1, output, visited);
    output.pop_back();
    visited[srcx][srcy+1] = false;
  }
  
}



int main() {

  int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1,1,1,0}, {1,1,1,1}};

  int row = 4, col = 4;
  int srcx = 0, srcy = 0;
  string output = "";

  // create visited 2D array
  vector<vector<bool>> visited(row, vector<bool>(col, false));

  if(maze[0][0] == 0) {
    cout << "No way bro :(" << endl;
  }else {
    printWays(maze, row, col, srcx, srcy, output, visited);
  }
 
  
  return 0;
}
