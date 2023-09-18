// https://leetcode.com/problems/find-the-duplicate-number

#include <iostream>
#include <vector>
using namespace std;

// my approach supported by hint :
// mark visited numbers as negative, if any number visited is negative, return its index
int findDuplicate(vector<int> &nums)
{

    int counter = 0, i = 0;

    while (counter <= nums.size())
    {
        if (nums[i] < 0)
            return i;

        nums[i] *= (-1);
        i = abs(nums[i]);
        counter++;
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 2};
    cout << "The duplicate number is: " << findDuplicate(nums) << endl;
    ;

    return 0;
}