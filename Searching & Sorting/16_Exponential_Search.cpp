// Exponential search | Doubling search | Stralic Search
// used in very large arrays | Unbounded / infinite arrays 

// Time complexity : https://photos.app.goo.gl/jJM4UEC1GnnFgQ517

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int s, int e, int target){
    while (s <= e){
        int m = s + (e - s) / 2;
        if (nums[m] == target){
            return m;
        }
        else if (nums[m] > target){
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }

    return -1;
}

int exponential_search(vector<int> &nums, int target)
{   
    if (nums[0] == target) return 0;

    int index = 1;

    while (index < nums.size() && nums[index] <= target){
        index *= 2;
    }
    int n = nums.size() - 1;
    return binarySearch(nums, index / 2, min(index, n), target);
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 50, 300, 344, 700, 900, 1001, 1029, 1221, 2001, 2229};

    int ans = exponential_search(nums, 2229);
    if (ans >= 0)
        cout << "Found @ " << ans << endl;
    else if(ans == -1)
        cout << "Not found : (" << endl;

    return 0;
}