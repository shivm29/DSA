// https://leetcode.com/problems/house-robber/
// TIME LIMIT EXCEEDED IN LEETCODE
// SOLVE THIS WITH DP "LATER"

//  Amazon ✯   Apple ✯   Google ✯   Cisco ✯   Microsoft ✯   Adobe   Bloomberg   Facebook   Walmart Global Tech

#include <iostream>
#include <vector>
using namespace std;

int maxRob(vector<int> &nums, int index){
    if (index >= nums.size())
        return 0;

    int include = nums[index] + maxRob(nums, index + 2);
    int exclude = maxRob(nums, index + 1);

    return max(include, exclude);
}


int main(){
    vector<int> nums = {2,4,1,6,8,5,9};
    cout << maxRob(nums, 0);
}