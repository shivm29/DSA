#include <iostream>
#include <vector>
using namespace std;


// Approach by me [if only 2 directions are allowed] : 
void printWays(vector<vector<int>> m, int i, int j, vector<vector<int>> v){
  if(i >= m.size() || j >= m[0].size()){
    if(!v.empty()) v.pop_back();
    return;
  }

  if(m[i][j] == 0) return;

  v.push_back({i,j});

  if(i == m.size()-1 && j == m[0].size()-1) {
    for(int x=0; x<v.size(); x++) {
      for(int y=0; y<v[x].size(); y++) {
        cout << v[x][y];
      }
      cout << "->";
    }
    cout << endl;
    v.pop_back();
    return;
  }

  // moving right
  printWays(m, i, j+1, v);
  // moving down
  printWays(m, i+1, j, v);
  v.pop_back();
}



int main() {

  vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1,1,1,0}, {1,1,1,1}};
  vector<vector<int>> v;
  printWays(m, 0, 0, v);
  
  return 0;
}
