// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BookAllocation(vector<int> &nums, int m){

    int sum = 0;

    for (auto i : nums){
        sum += i;
    }

    int minSum = sum;
    int leftSum = 0;

    for (int i = 0; i < nums.size() - 1; i++){
        leftSum += nums[i];
        int currMax = max(leftSum, sum - leftSum);
        minSum = min(minSum, currMax);
    }

    return minSum;
}

int main(){

    vector<int> nums = {12, 34, 67, 90};
    cout << "Ans : " << BookAllocation(nums, 3);

    return 0;
}

