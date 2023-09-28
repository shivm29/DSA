#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 0; j < nums.size() - 1; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

int main()
{

    vector<int> nums = {5, 4, 3, 2, 1};

    bubbleSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}