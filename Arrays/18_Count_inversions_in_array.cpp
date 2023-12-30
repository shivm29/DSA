#include <iostream>
using namespace std;

int main() {

    int arr[4] = {4,3,2,1};
    int inversions = 0;
    // using naive approach :  
    for(int i=0; i<3; i++) {
        for(int j = i+1; j < 4; j++) {
            if(arr[j] < arr[i]) inversions++;
        }
    }

    cout << "inversions count : " << inversions << endl;

    return 0;
}