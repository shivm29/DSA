// https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Medium
// Uber | Zoho | Adobe | Apple | Amazon | DoorDash | Bloomberg | Goldman Sacs

#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

// two pointers approach with set pair
int findPairs(vector<int>& nums, int k) {
    int i = 0, j = 1;
    set<pair <int, int>> ans;

    sort(nums.begin(), nums.end());

    while(j < nums.size()) {

        if(nums[j] - nums[i] == k) {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if ( nums[j] - nums[i] > k) i++;
        else j++;

        if(i == j) j++;

    }

    return ans.size();
}

// binary search approach : 
// TC => O(NlogN)
int bs(vector<int> &nums, int start, int x) {
    int end = nums.size()-1;
    while(start <= end) {
        int mid = start+ (end-start)/2;
        if(nums[mid] == x) {
            return mid;
        }
        else if(x > nums[mid]) start = mid+1;
        else end = mid-1;
    }

    return -1;
}

int findPairs(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(bs(nums, i+1, nums[i]+k) != -1) ans.insert({nums[i], nums[i]+k});
    }

    return ans.size();
}