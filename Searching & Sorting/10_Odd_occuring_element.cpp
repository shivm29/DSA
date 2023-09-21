#include <iostream>
#include <vector>
using namespace std;

int oddOccuringElement(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2; // 4
    int ans = -1;
    while (s <= e)
    {
        if(s == e) {
            return nums[s];
        }
        // if index is even :
        
        if (mid % 2 == 0)
        {
            if (mid < nums.size() - 2 && nums[mid] == nums[mid + 1])
            {
                s = mid + 2; // 4
            }
            else
            {
                ans = nums[mid]; // 2
                e = mid;         // 4
            }
        }
        else
        {
            if (mid >= 1 && nums[mid] == nums[mid - 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        mid = s + (e - s) / 2; // 2
    }

    return ans;
}

// ans = 2

int main()
{

    vector<int> nums = {1, 1, 5, 5, 2, 2, 3, 3, 9, 9, 10, 90, 90};
    //                  0  1  2  3  4  5  6  7  8

    cout << oddOccuringElement(nums) << endl;

    return 0;
}