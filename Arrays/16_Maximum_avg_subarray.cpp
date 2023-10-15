// https://leetcode.com/problems/maximum-average-subarray-i/description/

// Facebook
// Easy

#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double avg = 0;
    int j = 0;

    for(int i = 0; i < k; i++) {
        avg += nums[i];
    }

    double currAvg = avg;

    for(int i = 1; i <= nums.size()-k; i++) {
        currAvg -= nums[j];
        currAvg += nums[i+k-1];
        j++;
        
        if(currAvg > avg) avg = currAvg;
    }

    return avg/k;
}