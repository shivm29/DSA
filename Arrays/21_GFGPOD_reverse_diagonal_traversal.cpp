#include<iostream>
#include<vector>
using namespace std;

vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
{
    // Code here
    int n = matrix.size();
    if(n == 1) return matrix[0];
    
    vector<int> ans;
    
    // traversing cols 0 to n-1
    for(int c=0; c<n; c++) {
        int r = 0;
        ans.push_back(matrix[r][c]);
        int col = c;
        while(col != 0){
            col--; r++;
            ans.push_back(matrix[r][col]);
        }
    }
    
    // traversing rows 1 to n-1
    for(int r=1; r<n; r++) {
        int c = n-1;
        ans.push_back(matrix[r][c]);
        int row = r;
        while(row != n-1) {
            row++;
            c--;
            ans.push_back(matrix[row][c]);
        }
    }
    
    return ans;
}