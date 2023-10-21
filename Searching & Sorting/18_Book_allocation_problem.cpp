// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// Hard

#include<iostream>
#include<climits>
using namespace std;


bool isValid(int A[], int N, int M, int mid) {
    int sum = 0, count = 1;
    
    for(int i=0; i<N; i++) {
        if(sum + A[i] <= mid) sum += A[i];              // 46 <= 101
        else {
            count++;                                   // 2 
            if(count > M || A[i] > mid) return false;  
            sum = A[i];                                // 67
        }
    }
    
    return true;
}

//Function to find minimum number of pages.
int findPages(int A[], int N, int M){
    
    if(M > N) return -1;
    
    int s = 0, e = 0, ans = -1;
    
    for(int i=0; i<N; i++) {
    e += A[i];
    }
    
    int mid = s+(e-s)/2;
    
    while(s <= e) {
        
        if(isValid(A, N, M, mid)) {
            ans = mid;
            e = mid-1;
        }
        else {s = mid+1;}
        
        mid = s+(e-s)/2;
    }
    
    return ans;
}


int main() {

    int arr[4] = {12, 34, 67, 90};

    cout << findPages(arr,4,2);

    return 0;
}