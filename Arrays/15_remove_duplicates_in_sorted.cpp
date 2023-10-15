// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Facebook ✯   Amazon ✯   Adobe ✯   Microsoft ✯   LinkedIn ✯   Bloomberg   Google   Apple   VMware  

// Easy

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int j=1;

    for(int i=0; i<nums.size()-1; i++) {
        if(nums[i] != nums[i+1]) {
            nums[j] = nums[i+1];
            j++;
        }
    }

    return j;
}