// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = 0, actualSum = 0;

        for(int i = 0; i < nums.size()+1; i++) {
            expectedSum += i;
        }

        for(int i = 0; i < nums.size(); i++) {
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};