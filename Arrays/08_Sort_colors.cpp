#include <iostream>
#include <vector>
using namespace std;

// Approach I [By me]
// Time complexity : O(N)
void sortColors(vector<int> &nums)
{
    int mid = 0, lo = 0, hi = nums.size() - 1;

    while (mid < hi)
    {
        switch (nums[mid])
        {
        case 2:
            swap(nums[mid], nums[hi]);
            hi--;
            break;

        case 1:
            mid++;
            break;

        case 0:
            swap(nums[mid], nums[lo]);
            lo++;
            mid++;
            break;
        }
    }
}

// Approach II [by codehelp]
// Time complexity O(N)
void sortColorsII(vector<int> &nums) {
    int zeroCount = 0, oneCount = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) zeroCount++;
        else if(nums[i] == 1) oneCount++;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(i < zeroCount) nums[i] = 0;
        else if(i >= zeroCount && i < zeroCount+oneCount) nums[i] = 1;
        else nums[i] = 2;
    }
}


int main()
{

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    // before sorting :
    cout << "before sorting : " << endl;
    for (auto num : nums)
    {
        cout << num << " ";
    }
    sortColorsII(nums);

    // after sorting :
    cout << "after sorting : " << endl;
    for (auto num : nums)
    {
        cout << num << " ";
    };

    return 0;
}