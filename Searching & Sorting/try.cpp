#include <iostream>
#include <vector>
using namespace std;

int oddOccuringElement(vector<int> &nums)
{
    int ans = -1;

    int s = 0, e = nums.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            return nums[s];
        }
        
        if (m % 2 == 1)
        {
            if (m - 1 >= 0 && nums[m - 1] == nums[m])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        else
        {
            if (m + 1 <= nums.size() && nums[m] == nums[m + 1])
            {
                s = m + 2;
            }
            else
            {
                ans = nums[m];
                e = m;
            }
        }

        m = s + (e - s) / 2;
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 1, 5, 5, 2, 2, 3, 3, 9, 9, 10, 90, 90};
    //                  0  1  2  3  4  5  6  7  8  9  10  11  12

    cout << oddOccuringElement(nums) << endl;

    return 0;
}