#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;



bool isPresent(int arr[], int n, int target){

    int s = 0, e = n-1;
    while(s <= e) {
        int m = s + (e-s)/2;

        if(arr[m] == target) return true;
        else if(arr[m] > target) e = m-1;
        else s = m+1;
    }

    return false;
}

// Approach I
// Time complexity O(N1 * log max(N1, N2))
vector<int> commonElements(int arr1[], int arr2[], int arr3[], int s1, int s2, int s3) {
    
    vector<int> ans;

    for(int i = 0; i < s1; i++) {
        if(isPresent(arr2, s2, arr1[i]) && isPresent(arr2, s2, arr1[i])) ans.push_back(arr1[i]);
    }

    return ans;
}


// Approach II
vector<int> commonElementsII(int arr1[], int arr2[], int arr3[], int s1, int s2, int s3){

    vector<int> ans;

    for(int i = 0; i < s1; i++) {
        if(isPresent(arr2, s2, arr2[i])) ans.push_back(arr1[i]);
    }

    for(int i=0; i<ans.size(); i++) {
        if(!isPresent(arr3, s3, ans[i])){
            ans.erase(ans.begin()+i); 
        }
    }


    return ans;
}


// Approach III
// Three pointer approach
vector<int> commonElementsIII(int arr1[], int arr2[], int arr3[], int s1, int s2, int s3){

    vector<int> ans;
    int i1 = 0, i2 = 0, i3 = 0;

    while(i1 < s1) {
        if(i2 < s2 && arr1[i1] == arr2[i2]) {
            if(i3 < s3 && arr1[i1] == arr3[i3]) {
                ans.push_back(arr1[i1]);
                i1++;
                i2++;
                i3++;
            }
            else if(i3 < s3 && arr1[i1] > arr3[i3]) i3++;
            else i1++;
        }
        else if (i2 < s2 && arr1[i1] > arr2[i2]) i2++;
        else i1++;
    }

    return ans;
   
}


int main() {

    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {16, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int>
        ans = commonElementsIII(ar1, ar2, ar3, 6, 5, 8);
    cout << "Common elements are : " << endl;
    for(auto i: ans) {
        cout << i << " " ;
    } 

    return 0;
    
}