// https://leetcode.com/problems/find-pivot-index
#include <iostream>
#include <vector>
using namespace std;

// Two pointer method [By me]
// Note : This approach is not working on leetcode
/* Line 1037: Char 34: runtime error: addition of unsigned offset to 0x6020000001d0 overflowed to 0x6020000001cc (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_vector.h:1046:34
*/
// Time complexity : O(N)
int pivotIndexI(vector<int> &nums)
{
    int leftSum = 0, rightSum = 0;
    int lo = 0, hi = nums.size() - 1;

    leftSum = nums[lo];
    rightSum = nums[hi];

    for (int i = 0; i < nums.size(); i++)
    {

        if (leftSum == rightSum && lo == hi - 2)
        {
            return lo + 1;
        }
        else if (leftSum >= rightSum)
        {
            hi--;
            rightSum += nums[hi];
        }
        else
        {
            lo++;
            leftSum += nums[lo];
        }
    }

    return -1;
}

// Approach II [By me]
// Time complexity O(N)
int pivotIndexII(vector<int> &nums)
{
    int leftSum = 0, totalSum = 0;

    for (auto el : nums)
    {
        totalSum += el;
    }

    for (int i = 0; i < nums.size(); i++)
    {

        if (leftSum == (totalSum - nums[i] - leftSum))
        {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}

// Approach III [by code help]
// Time complexity O(N)
int pivotIndexIII(vector<int> &nums)
{

    vector<int> leftSum(nums.size(), 0), rightSum(nums.size(), 0);
    leftSum[0] = 0;
    rightSum[nums.size() - 1] = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (leftSum[i] == rightSum[i])
            return i;
    }

    return -1;
}

int main()
{

    vector<int> nums = {1, 2, 3};
    cout << "Pivot Index: " << pivotIndexIII(nums) << endl;

    return 0;
}