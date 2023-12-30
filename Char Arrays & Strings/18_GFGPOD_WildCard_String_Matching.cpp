// https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1
#include <iostream>
#include <vector>
using namespace std;

bool helper(string wild, string pattern, int i, int j, int n, int m, vector<vector<int>> &dp) {
    
    // successfully traversed both strings til the end
    if(i == n && j == m) return true;
    if(i >= n || j >= m) return false;
    
    // if a particular situation was already solved return the stored result
    if(dp[i][j] != -1) return dp[i][j];
    
    if(wild[i] == pattern[j] || wild[i] == '?') {
        bool ans = helper(wild, pattern, i+1, j+1, n, m, dp);
        dp[i][j] = ans;
        return ans;
    }
    
    bool ans = false;
    if(wild[i] == '*') {
        for(int k=j; k<=m; k++) {
            ans |= (helper(wild, pattern, i+1, k, n, m, dp));
        }
        
        dp[i][j] = ans;
        return ans;
    }
    
    dp[i][j] = false;
    return false;
}

bool match(string wild, string pattern)
{
    // code here
    int n = wild.size();
    int m = pattern.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    return helper(wild,pattern,0,0,n,m,dp);
}