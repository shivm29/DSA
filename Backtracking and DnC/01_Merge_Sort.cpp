#include <iostream>
using namespace std;

void merge(int A[], int N, int s, int e) {

    if(s <= e) return;

    int mid = s + (e-s)/2;
    
    int leftLen = mid - s + 1;
    int rightLen = e - mid;

    // create left and right array : 
    int *left = new int[leftLen];
    int *right = new int[rightLen];

    int k = s;

    for(int i=0; i<leftLen; i++) {
        left[i] = A[k];
        k++;
    }

    k = mid+1;

    for(int i=0; i<rightLen; i++) {
        right[i] = A[k];
        k++;
    }

    // left and right arrays are already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    // for main array : 
    int mainIndex = s;

    while(leftIndex < leftLen && rightIndex < rightLen) {
        if(left[leftIndex] < right[rightIndex]) {
            A[mainIndex] = left[leftIndex];
            leftIndex++;
            mainIndex++;
        }
        else {
            A[mainIndex] = right[rightIndex];
            rightIndex++;
            mainIndex++;
        }
    }

    while(leftIndex < leftLen) {
        A[mainIndex] = left[leftIndex];
        leftIndex++;
        mainIndex++;
    }
    while(rightIndex < rightLen) {
        A[mainIndex] = right[rightIndex];
        rightIndex++;
        mainIndex++;
    }

}

void mergeSort(int A[], int N, int s, int e) {
    // base case : [if array is of 0 or 1 size that's already sorted]
    if(s <= e) return;

    int mid = s + (e-s)/2;
    // for left part
    mergeSort(A, N, s, mid);
    // for right part
    mergeSort(A, N, mid+1, e);

    return merge(A,N, s, e);
}

int main() {

    int arr[] = {5, -3, 44, -7, 8};
    mergeSort(arr, 5, 0,4);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}