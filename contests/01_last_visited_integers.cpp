// https://leetcode.com/contest/biweekly-contest-115/problems/last-visited-integers/
#include <iostream>
#include <vector>
using namespace std;
  

vector<int> lastVisitedIntegers(vector<string>& words) {
    vector<int> nums;
    int index;
    vector<int> ans;
    
    for(int i = 0; i < words.size(); i++) {
        if(words[i] != "prev") {
            nums.push_back(stoi(words[i]));
            index = nums.size()-1;
        }
        else {
            if(index < 0 || nums.empty())ans.push_back(-1);
            else {
                ans.push_back(nums[index]);
                index--;
            }
        }
    }
    return ans;
}