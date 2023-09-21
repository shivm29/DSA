// https://leetcode.com/problems/search-a-2d-matrix/
#include <iostream>
#include <vector>
using namespace std;

// convert the 2d array to 1d  | Binary search 
bool search2D(vector<vector<int>> &nums, int target)
{

    int row = nums.size();
    int col = nums[0].size();
    int s = 0, e = row * col - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {

        int rowIndex = m / col;
        int colIndex = m % col;
        int currentNumber = nums[rowIndex][colIndex];

        if (currentNumber == target)
        {
            return true;
        }
        else if (currentNumber > target)
        {
            e = m - 1;
        }
        else
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return false;
}

int main()
{

    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << search2D(nums, 16);

    return 0;
}