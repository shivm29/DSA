// https://leetcode.com/contest/biweekly-contest-115/problems/longest-unequal-adjacent-groups-subsequence-i/
#include <iostream>
#include <vector>
using namespace std;

vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
    
    
    int i = 0, j = 1;
    vector<int> ans;
    vector<string> finalAns;
    
    if(n == 0) return finalAns;
    
    if(n == 1){
        finalAns.push_back(words[0]);
        return finalAns;
    }
    
    ans.push_back(0);
    
    while(j < n && i < n) {
        if(groups[i] != groups[j]) {
                ans.push_back(j);
                i = j;
                j++;
        }
        else {
            j++;
        }
    }
    
    for(auto i: ans) {
        finalAns.push_back(words[i]);
    }
    
    
    return finalAns;
}