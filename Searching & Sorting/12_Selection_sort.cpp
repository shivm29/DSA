#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int min = i;

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min])
                min = j;
        }

        swap(nums[min], nums[i]);
    }
}
int main()
{

    vector<int> nums = {5, 4, 3, 2, 1};

    selectionSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}