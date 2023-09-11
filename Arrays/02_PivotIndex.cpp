// https://leetcode.com/problems/find-pivot-index/
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int leftSum = 0, totalSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (totalSum - nums[i] == 2 * leftSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};
