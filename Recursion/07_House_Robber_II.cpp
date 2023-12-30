// https://leetcode.com/problems/house-robber-ii/
// TIME LIMIT EXCEEDED IN LEETCODE
// SOLVE THIS WITH DP "LATER"

//  Amazon  ✯   Google ✯

#include <iostream>
#include <vector>
using namespace std;

int maxRob(vector<int> &nums, int index, int size) {
    if(index >= size) return 0;

    int include = nums[index] + maxRob(nums, index+2, size);
    int exclude = maxRob(nums, index+1, size);

    return max(include, exclude);
}

int rob(vector<int>& nums) {
    int ans1, ans2;

    ans1 = nums[0] + maxRob(nums, 2, nums.size()-1);
    ans2 = maxRob(nums, 1, nums.size());

    return max(ans1, ans2);
}