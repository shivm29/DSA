#include <iostream>
using namespace std;

// 0 2 
// 0 1 

int inversionCount = 0;

void merge(int arr[], int s, int e) {
    // if (s >= e) return;

    int mid = s + (e-s)/2;
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    int *left = new int[leftLength];
    int *right = new int[rightLength];
    

    int k = s;
    for(int i=0; i<leftLength; i++) {
        left[i] = arr[k];
        k++;
    }
    k = mid+1;
    for(int i=0; i<rightLength; i++) {
        right[i] = arr[k];
        k++;
    }

    // count inversions : 
    int l = 0, r = 0;
    while(r < rightLength && l < leftLength) {
        if(right[r] < left[l]){
            inversionCount += leftLength-l;
            r++;
            
        }
        else {
            l++;
        }
    }

    int leftIndex = 0, rightIndex = 0, mainIndex = s;



    while(leftIndex < leftLength && rightIndex < rightLength) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }

    while(leftIndex < leftLength) {
        arr[mainIndex] = left[leftIndex];
        mainIndex++;
        leftIndex++;
    }

    while (rightIndex < rightLength)
    {
        arr[mainIndex] = right[rightIndex];
        mainIndex++;
        rightIndex++;
    }

    delete[] left;
    delete[] right;

    return;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e) return;

    int mid = s + (e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main() {

    int arr[] = {5,4,3,2,1,0};
    mergeSort(arr, 0,5);

    for(int i=0; i<6; i++) {
        cout << arr[i] << " ";
    }

    cout << "inversion count : " << inversionCount << endl;

    return 0;
}