// https://leetcode.com/problems/missing-number/
#include <iostream>
#include <vector>
using namespace std;

// TC : O(N) SC : O(1)
// XOR Method
int missingNumberI(vector<int> nums)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= (i + 1) ^ nums[i];
    }

    return ans;
}

// Sum method
// TC : O(N) SC : O(1) [problem : overflow possibility during sum of big numbers]
int missingNumberII(vector<int> nums)
{
    int sum = 0, expectedSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        expectedSum += (i + 1);
    }

    return expectedSum - sum;
}

int main()
{

    vector<int> nums = {0, 3, 4, 1, 5, 6, 2, 7, 9};
    cout << "missing number is : " << missingNumberII(nums);

    return 0;
}