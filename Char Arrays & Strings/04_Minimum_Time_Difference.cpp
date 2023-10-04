// https://leetcode.com/problems/minimum-time-difference/

// Medium
// Google Amazon

#include <iostream>
#include <string.h>
#include<vector>
#include<algorithm>
using namespace std;


// Approach from leetcode solutions
int findMinDifference(vector<string>& timePoints) {

    vector<int> mins;
    for(int i = 0; i < timePoints.size(); i++) {
        int min = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
        mins.push_back(min);
    }

    sort(mins.begin(), mins.end());
    int ans = 100000;

    for(int i = 1; i < mins.size(); i++) {
        
        ans = min(ans, mins[i] - mins[i-1]);
    }

    ans = min(ans, 1440+mins[0] - mins[mins.size()-1]);

    return ans;

}   


// My approach | Time limit exceeded  in leetcode | O(N)
int findMinDifference(vector<string>& timePoints) {
    int ans = 999999;

    for(int i = 0; i < timePoints.size()-1; i++) {
        for(int j = i+1; j < timePoints.size(); j++  ){
            int time1, time2, curr;
            time1 = stoi(timePoints[i].substr(0,2))*60 + stoi( timePoints[i].substr(3,2));
            time2 = stoi(timePoints[j].substr(0,2))*60 + stoi( timePoints[j].substr(3,2));

            curr = min(24*60 - abs(time1 - time2), abs(time1-time2));
            ans = min(ans, curr);
        }
    }

    return ans;
}   


int main() {


    return 0;
}