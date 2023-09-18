// https://practice.geeksforgeeks.org/problems/key-pair5616/1
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// bruteforce approach :
bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
                return true;
        }
    }

    return false;
}

// efficient approach I (using unordered map)
vector<int> twoSumI(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    int store;

    for (int i = 0; i < nums.size(); i++)
    {
        store = target - nums[i];
        if (map.count(store) > 0)
        {
            return {map[store], i};
        }
        else
        {
            map[nums[i]] = i;
        }
    }

    return {};
}

// efficient approach using two pointers method :
vector<int> twoSumII(vector<int> &nums, int target)
{

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end()); // O(N logN)
    int lo = 0, hi = nums.size() - 1;
    vector<int> ans;

    while (lo < hi)
    {
        if (sorted[lo] + sorted[hi] == target)
            break;
        else if (sorted[lo] + sorted[hi] > target)
            hi--;
        else
            lo++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == sorted[lo] || nums[i] == sorted[hi])
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {1, 4, 45, 6, 10, 8};
    int x = 16;

    vector<int> ans = twoSumII(v, 16);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}