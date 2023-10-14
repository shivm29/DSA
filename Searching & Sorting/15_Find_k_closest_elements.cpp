// https://leetcode.com/problems/find-k-closest-elements/

// Medium
// Uber | google | tiktok | amazon | oracle | facebook | bloomberg

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// lower bound and Binary search approach----------------------------
int lowerBound(vector<int> &arr, int x) {
    int start = 0, end = arr.size()-1;
    int ans = end;

    while(start<=end) {
        int mid = (start+end)/2;

        if(arr[mid] >= x) {
            ans = mid;
            end = mid-1;
        }
        else if(x > arr[mid]) {
            start = mid+1;
        }

    }


    return ans;
}

vector<int> bs_method(vector<int> &arr, int k, int x) {
    // lower  bound
    int h = lowerBound(arr, x);
    int l = h-1;

    while(k--) {
        if(l < 0) h++;
        else if(h >= arr.size()) l--;
        else if(x-arr[l] > arr[h] - x) h++;
        else l--;
    }

    return vector<int>(arr.begin()+l+1, arr.begin()+h);
}


// Two pointer approach ----------------------------------------
vector<int> twoPtr(vector<int> &arr, int k, int x) {
    int lo = 0, hi = arr.size()-1;
    while(hi-lo != k-1){
        if(abs(x-arr[hi]) >= abs(x-arr[lo]) ) hi--;
        else lo++;
    }

    return {lo, hi};
}

vector<int> findClosestElements(vector<int> &arr, int k, int x){
    
    vector<int> loAndHi = twoPtr(arr, k, x);
    vector<int> ans;
    for(int i = loAndHi[0]; i<= loAndHi[1]; i++) {
        ans.push_back(arr[i]);
    }

    return ans;
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = findClosestElements(nums, 4, -1);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
