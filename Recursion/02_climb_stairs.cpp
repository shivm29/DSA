// https://leetcode.com/problems/climbing-stairs/
// Easy
// Uber   Adobe   Yahoo   Amazon   Google   Expedia   Microsoft   Bloomberg   Goldman Sachs 

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Time limit exceeded on leetcode
int climbStairsRecursive(int n) {
//    base case : 
    if(n == 0) return 1;
    if(n == 1) return 1;

    int ans = climbStairsRecursive(n-1)+climbStairsRecursive(n-2);

    return ans;
}


// Recursion + memory - works on leetcode
int calculateWays(int n, unordered_map<int, int> &memo) {
    // base case
    if(n == 0 || n == 1) return 1;

    if(memo.find(n) == memo.end()) {
        memo[n] = calculateWays(n-1, memo) + calculateWays(n-2,memo);
    }
    return memo[n];

}

int climbStairsUsingMemo(int n) {
//    base case : 
    if(n == 0) return 1;
    if(n == 1) return 1;

    int ans = climbStairsUsingMemo(n-1)+climbStairsUsingMemo(n-2);

    return ans;
}

// using DP : 
int climbStairsUsingDP(int n) {
    if(n == 0 || n == 1) return 1;

    vector<int> dp(n+1);
    dp[0] = dp[1]  = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// best solution | Space Optimized
int climbStairsBestSolution(int n) {
    if(n == 0 || n == 1) return 1;

    int prev = 1, curr = 1;
    for(int i = 2; i <= n; i++) {
        int temp = curr;
        curr = curr+prev;
        prev = temp;
    }

    return curr;
}